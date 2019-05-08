
// Map2View.cpp : implementation of the CMap2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Map2.h"
#endif

#include "Map2Doc.h"
#include "Map2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMap2View

IMPLEMENT_DYNCREATE(CMap2View, CView)

BEGIN_MESSAGE_MAP(CMap2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMap2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMap2View construction/destruction

CMap2View::CMap2View() noexcept
{
	// TODO: add construction code here

}

CMap2View::~CMap2View()
{
}

BOOL CMap2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMap2View drawing

void CMap2View::OnDraw(CDC* /*pDC*/)
{
	CMap2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMap2View printing


void CMap2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMap2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMap2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMap2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMap2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMap2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMap2View diagnostics

#ifdef _DEBUG
void CMap2View::AssertValid() const
{
	CView::AssertValid();
}

void CMap2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMap2Doc* CMap2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMap2Doc)));
	return (CMap2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMap2View message handlers


void CMap2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.SetMapMode(MM_LOMETRIC);
	CRect rect;
	GetClientRect(&rect);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
	dc.SelectObject(&pen);
	dc.MoveTo(0, -500);
	dc.LineTo(0, 500);
	dc.MoveTo(500, 0);
	dc.LineTo(-500, 0);
	dc.TextOut(250, 250, "I");
	dc.TextOut(250, -250, "II");
	dc.TextOut(-250, -250, "III");
	dc.TextOut(-250, 250, "IV");
	dc.TextOut(10, -10, "(0,0)");
	dc.SetTextColor(RGB(0, 0, 255));
	dc.TextOut(495, 25, ">x");
	dc.TextOut(0, 500, "^y");
	CView::OnLButtonDown(nFlags, point);
}


void CMap2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.SetMapMode(MM_LOMETRIC);
	CRect rect;
	GetClientRect(&rect);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	dc.MoveTo(-500, -500);
	dc.LineTo(500, 500);
	dc.MoveTo(500, -500);
	dc.LineTo(-500, 500);
	CView::OnRButtonDown(nFlags, point);
}
