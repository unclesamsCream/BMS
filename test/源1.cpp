#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;
class Message
{
private:
	static list<string> split(string str, char dim);
public:
	static map<string, string> parse(string str);
	static string serialize(map<string, string> m);
};

list<string> Message::split(string  str, char dim)
{
	char* d = &dim;
	list<string> ls;

	char* strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char* p = strtok(strs, d);
	while (p) {
		string s = p;
		ls.push_back(s);
		p = strtok(NULL, d);
	}
	return ls;
}

string Message::serialize(map<string, string> m)
{
	string str;
	map<string, string>::iterator iter = m.begin();
	while (1)
	{

		str += iter->first + "=" + iter->second;
		++iter;
		if (iter != m.end())
		{
			str += " ";
		}
		else
		{
			break;
		}
	}
	return str;
}

map<string, string> Message::parse(string str)
{
	map<string, string> mm;
	list<string> ll = split(str, ' ');
	list<string>::iterator iter;
	string temp;
	for (iter = ll.begin(); iter != ll.end(); ++iter)
	{
		temp = *iter;
		int i = temp.find('=');
		mm[temp.substr(0, i)] = temp.substr(i+1);
	}
	return mm;
}

//int main()
//{
//	string s = "name=LoginController idCard=131231321231231231231 password=123456";
//	map<string,string> m = Message::parse(s);
//	map<string, string>::iterator iter = m.begin();
//
//
//	string ss = Message::serialize(m);
//	cout << ss << endl;
//	map<string, string> mm = Message::parse(ss);
//
//	map<string, string>::iterator iter1 = mm.begin();
//	while (iter1 != mm.end())
//	{
//		cout << iter1->first << ":" << iter1->second << endl;
//		++iter1;
//	}
//}