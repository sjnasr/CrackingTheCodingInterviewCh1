#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void bubbleSort(vector<int> &nums)
{
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		for(unsigned int j = 0; j < nums.size() - i - 1; j++)
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
	}
}

//start from back and go forward
bool isUnique(string str)
{
	if (str.length() > 128)
	{
		return false;
	}

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}
	return true;
}

//Take in 2 strings
//check if strings length are the same, if not, return false
//Compare both
bool isPermutation(string str1, string str2)
{
	if (str1.length() == NULL || str2.length() == NULL)
	{
		return false;
	}

	if (str1.length() != str2.length())
	{
		return false;
	}
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

//copy one string to another
string URLify(string &str)
{
	if (str.length() == NULL)
	{
		return "no string was entered";
	}

	int len = str.length();
	char* t = new char[3 * len];//incase all are spaces
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ')
			t[k++] = str[i];
		else {
			t[k] = '%';
			t[k + 1] = '2';
			t[k + 2] = '0';
			k = k + 3;
		}
	}

	t[k] = '\0';
	return t;
}



//Find all prime numbers up to N
//half the numbers are prime so in the loop divide by half
bool isPrime(int num)
{
	try {
		for (int i = 2; i <= num / 2; i++)
		{
			if (num %i == 0)
			{
				return false;
			}
		}
		return true;

	}
	catch (exception &e)
	{
		cout << "Error: " << e.what() << endl;
	}
}

bool checkMaxOneOdd(vector<int> &table)
{
	bool foundOdd = false;

	for (int count : table)
	{
		if (count % 2 == 1)
		{
			if (foundOdd)
			{
				return false;
			}
			foundOdd = true;
		}
	}
	return true;
}

//Palindrome Permutation helper 1
int getCharNumber(const char & c) {
	int a = (int) 'a';
	int z = (int) 'z';
	int A = (int) 'A';
	int Z = (int) 'Z';
	int val = (int)c;
	if (a <= val && val <= z) {
		return val - 'a';
	}
	else if (A <= val && val <= Z) {
		return val - 'A';
	}
	return -1;
}

//Palindrome Permutation helper 1
vector <int> buildCharFrequencyTable(string phrase) {
	vector <int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);
	for (char &c : phrase) {
		int x = getCharNumber(c);
		if (x != -1) {
			table[x]++;
		}
	}
	return table;
}

//Check if word is a palindrome Permutation
bool palindromePermutation(string words)
{
	vector<int> table = buildCharFrequencyTable(words);
	return checkMaxOneOdd(table);
}

//Check if the string was only altered once, return true if yes, if more than once then return false
bool oneAway(string str1, string str2)
{
	int count = 0;
	if (abs(str1.length() - str2.length() > 1))
	{
		return false;
	}
	
	int i = 0, j = 0;
	while (i < str1.length() && j < str2.length())
	{
		if (str1[i] != str2[j])
		{
			if (count == 1)
			{
				return false;
			}

			if (str1.length() > str2.length())
			{
				i++;
			}
			else if (str1.length() < str2.length())
			{
				j++;
			}
			count++;
		}
		else
		{
			i++;
			j++;
		}
	}

	if (i < str1.length() || j < str2.length())
	{
		count++;
	}

	return count = 1;
}

/*1.6 Compress String*/
//Compresses the string if there are multiple letters
string compression(string str)
{
	int count = 1;
	string newStr;
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			count++;
		} 
		else
		{
			newStr.push_back(str[i]);
			newStr.append(to_string(count));
			if (count > 1)
			{
				count = 1;
			}
		}
	}

	newStr.push_back(str.back());
	newStr.append(to_string(count));
	return newStr;
}

/*1.7 Rotate Matrix*/
void rotateMatrix(vector<vector<int>>& input)
{
	int row = input.size();
	for (int i = 0; i < row / 2; i++) //row
	{
		for (int j = 0; j < input[i].size() - i - 1; j++) //col
		{
			int temp = input[i][j];
			input[i][j] = input[input.size() - 1 - j][i];
			input[input.size() - 1 - j][i] = input[input.size() - 1 - i][input.size() - 1 - j];
			input[input.size() - 1 - i][input.size() - 1 - j] = input[j][input.size() - 1 - i];
			input[j][input.size() - 1 - i] = temp;
		}
	}
}

//1.8 Zero Matrix
void zeroMatrix(int matrix[2][2], int row, int col)
{
	vector<char> rowZeros(row, true);
	vector<char> colZeros(col, true);

	//find all zeros
	for (int i = 0; i < row; i++) //row
	{
		for (int j = 0; j < col; j++) //col
		{
			if (matrix[i][j] == 0)
			{
				rowZeros[i] = false;
				colZeros[j] = false;
			}
		}
	}

	//replace the values
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (!rowZeros[i] || !colZeros[j])
			{
				matrix[i][j] = 0;
			}
		}
	}
}

bool isStringRotation(string s1, string s2)
{
	/*Check if sizes of two strings are same */
	if (s1.length() != s2.length())
		return false;

	string temp = s1 + s1;

	return (temp.find(s2) != string::npos);
}

/*
**1.1 IsUnique
**1.2 CheckPermutation
**1.3 URLify
**1.4 Palindrome Permutation
**1.5 One Away
**1.6 String Compression
**1.7 Rotate Matrix
**1.8 Zero Matrix
**1.9 String Rotation
*/
int main()
{
	vector<int> nums = { 5, 2, 1, 3, 4 };
	bubbleSort(nums);

	//test cases for 1.1
	string name = "Sara"; //return false
	string name2 = "Alex"; //return true;

	cout << "Is unique? " << (isUnique(name) ? "yes" : "no") << endl;
	cout << "Is unique? " << (isUnique(name2) ? "yes" : "no") << endl;

	//test cases for 1.2
	string str1 = "mane";
	string str2 = "name"; //return true

	string str3 = "bug";
	string str4 = "gum"; //return false

	string str5 = "ham";
	string str6 = "sham"; //return false

	cout << "Is permutation? " << (isPermutation(str1, str2) ? "yes" : "no") << endl;
	cout << "Is permutation? " << (isPermutation(str3, str4) ? "yes" : "no") << endl;
	cout << "Is permutation? " << (isPermutation(str5, str6) ? "yes" : "no") << endl;

	string test = "Mr John Smith"; //return Mr%20John%20Smith

	cout << "Replace spaces " << URLify(test) << endl;

	//is prime checking
	int num1 = 257; //return true
	int num2 = 10; //return false
	cout << "Is " << num1 << " prime? " << (isPrime(num1) ? "yes" : "no") << endl;
	cout << "Is " << num2 << " prime? " << (isPrime(num2) ? "yes" : "no") << endl;


	/*1.4 testing*/
	string pali = "Rats live on no evil star";
	string pali2 = "Taco cat";
	cout << "Is " << pali << "a palindrome permutation? " << (palindromePermutation(pali) ? "yes" : "no") << endl;
	cout << "Is " << pali2 << "a palindrome permutation? " << (palindromePermutation(pali2) ? "yes" : "no") << endl;

	/*1.5 One Away*/
	string test1 = "pale";
	string test2 = "ple"; //return true

	string test3 = "pale";
	string test4 = "bake"; //return no

	cout << "Is " << test1 << " one away from " << test2 << "? " << (oneAway(test1, test2) ? "yes" : "no") << endl;
	cout << "Is " << test3 << " one away from " << test4 << "? " << (oneAway(test3, test4) ? "yes" : "no") << endl;

	/*1.6 String Compression tests*/
	string compress = "aabcccccaaa"; //output a2b1c5a3

	cout << compress << ": " << compression(compress) << endl;

	/*1.7 Rotate matrix test*/
	vector<vector<int>> testing = { {1, 2}, {1, 2} };
	rotateMatrix(testing);
	for (int i = 0; i < testing.size(); i++)
	{
		for (int j = 0; j < testing[i].size(); j++)
		{
			cout << testing[i][j] << " ";
		}
		cout << endl;
	}

	/*1.8 Zero Matrix*/
	int mat[2][2] = { {0,1}, {2,2} };

	zeroMatrix(mat, 2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	/*1.9 String Rotation*/
	string rotate1 = "waterbottle";
	string rotate2 = "erbottlewat"; //return true

	string rotate3 = "air";
	string rotate4 = "rie"; //return false

	string rotate5 = "AACD";
	string rotate6 = "ACDA";

	cout << "Is " << rotate2 << " a rotation of " << rotate1 << "? " << (isStringRotation(rotate1, rotate2) ? "yes" : "no") << endl;
	cout << "Is " << rotate4 << " a rotation of " << rotate3 << "? " << (isStringRotation(rotate3, rotate4) ? "yes" : "no") << endl;
	cout << "Is " << rotate6 << " a rotation of " << rotate5 << "? " << (isStringRotation(rotate5, rotate6) ? "yes" : "no") << endl;

	return 0;
}