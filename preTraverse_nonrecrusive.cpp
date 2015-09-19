// preTraverse_nonrecrusive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;


struct  node
{
	node(int d=0):data(d),pleft(NULL),pright(NULL){}
	int data;
	node* pleft;
	node* pright;
};

node* createBinaryTree()
{
	node* n1=new node(1);
	node* n2=new node(2);
	node* n3=new node(3);
	node* n4=new node(4);
	node* n5=new node(5);
	node* n6=new node(6);
	node* n7=new node(7);
	n1->pleft=n2;
	n1->pright=n3;
	n2->pleft=n4;
	n2->pright=n5;
	n3->pleft=n6;
	n3->pright=n7;
	return n1;

}

//非递归形式的二叉树的前序遍历
void pretraverse(node* proot)
{
	stack<node*> sk;
	if (proot==NULL)
	{
		return;
	}
	sk.push(proot);
	node* pcur=proot;
	while (!sk.empty())
	{
		pcur=sk.top();
		sk.pop();
		cout<<pcur->data<<"　";
		if (pcur->pright!=NULL)
		{
			sk.push(pcur->pright);
		}
		if (pcur->pleft!=NULL)
		{
			sk.push(pcur->pleft);
		}
	}
}

//非递归形式的二叉树的中序遍历
void inodertraverse(node* proot)
{
	stack<node*> sk;
	if (proot==NULL)
	{
		return;
	}
	node* pcur=proot;
	
	while (!sk.empty()||pcur!=NULL)
	{
		if (pcur!=NULL)
		{
			sk.push(pcur);
			pcur=pcur->pleft;
		}
		else
		{
			pcur=sk.top();
			cout<<pcur->data<<" ";
			sk.pop();
			pcur=pcur->pright;
		}
	}
}

void posttraverse(node* proot)
{
	stack<node*> sk1;
	stack<node*> sk2;
	if(proot==NULL)
		return;
	sk1.push(proot);
	node* pcur=proot;
	while (!sk1.empty())
	{
		pcur=sk1.top();
		sk1.pop();
		sk2.push(pcur);
		if (pcur->pleft)
		{
			sk1.push(pcur->pleft);
		}
		if (pcur->pright)
		{
			sk1.push(pcur->pright);
		}
	}
	while (!sk2.empty())
	{
		cout<<sk2.top()->data<<" ";
		sk2.pop();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	node* proot=createBinaryTree();
	cout<<"前序遍历"<<endl;
	pretraverse(proot);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	inodertraverse(proot);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	posttraverse(proot);
	return 0;
}

