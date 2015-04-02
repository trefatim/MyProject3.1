#include <string>
#include <iostream>
using namespace std;

struct List
{
	int i;
	List *pNext;
};

/*! Добавление элемента в список.
 * \param [in] pF − указатель на первый элемент.
 * \param [in] index − индекс удаляемого элемента.
 * \param [in] count − кол-во элементов.
 */
void del(List*& pF, int index, int count)
{
	if (index>count || index<1)
	{
		cout<<"wrong";
	}
	else if (index==1) 
	{
		pF=pF->pNext;
	}
	else if(count==index)
	{
		List *pPred=pF;
		for(int i=0; i<index-2; i++)
		{
			pPred=pPred->pNext;
		}
		pPred->pNext=NULL;
	}
	else
	{
		List *pPred=pF, *pFront;
		pFront=pPred->pNext;
		pFront=pFront->pNext;
		for(int i=0; i<index-2; i++)
		{
			pPred=pPred->pNext;
			pFront=pFront->pNext;
		}
		pPred->pNext=pFront;
	}
}

/*! Добавление элемента в список.
 * \param [in] pF − указатель на первый элемент.
 * \param [in] p − указатель на добавляемый элемент.
 * \param [in] index − индекс, куда добавить элемент.
 * \param [in] count − кол-во элементов.
 */
void add(List *&pF, List *p, int index, int count)	
{
	if (index>count+1 || index<1)
	{
		cout<<"wrong";
	}
	else if (index==1) 
	{
		p->pNext=pF;
		pF=p;
	}
	else if(count+1==index)
	{
		List *pPred=pF;
		for(int i=0; i<index-2; i++)
		{
			pPred=pPred->pNext;
		}
		pPred->pNext=p;
	}
	else
	{
		List *pPred=pF, *pFront;
		pFront=pF->pNext;
		for(int i=0; i<index-2; i++)
		{
			pPred=pPred->pNext;
			pFront=pFront->pNext;
		}
		p->pNext=pFront;
		pPred->pNext=p;
	}
}

//!Функция main
int main()
{
	List *p, *pFirst=NULL;
	int n, k=0, index,value, count=0;//!<кол-во действий, счетчик действий, значение элемента, счетчик элементов
	string mode;//!<операция над очередью
	cout<<"n="; cin>>n;
	while (k!=n)
	{
		cout<<"mode=";
		fflush(stdin);
		getline(cin,mode);
		if(mode=="add")
		{
			cin>>index;
			cin>>value;
			p=new List;
			p->i=value;
			p->pNext=NULL;
			add(pFirst,p,index, count);
			count++;
			k++;
		}
		else if(mode=="del")
		{
			cin>>index;
			del(pFirst,index,count);
			count--;
			k++;
		}
		else
		{
			cout<<"wrong";
		}
	}
	List *pi=pFirst;
	while(pi!=NULL)
	{
		cout<<pi->i<<" ";
		pi=pi->pNext;
	}
	system("pause");
	return 0;
}
