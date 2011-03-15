$NetBSD: patch-windows_MenuProc.c,v 1.1 2011/03/15 11:30:05 obache Exp $

* remove needless cast

--- windows/MenuProc.c.orig	2001-01-12 07:21:49.000000000 +0000
+++ windows/MenuProc.c
@@ -263,7 +263,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		mnis.wAction = LCA_SELECTION;
 		wPrevSel = (WORD)LBoxAPI(hMenu32,LBA_GETDATA,(LPARAM)&mnis);
 		if ((wSel == wPrevSel) || (wSel == (WORD)-1)) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 		ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,wSel);
@@ -279,7 +279,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			GET_WM_MENUSELECT_MPS(wItemID,LOWORD(lFlags),hMenu));
 		if (!((lFlags & MF_POPUP) &&
 			!(lFlags & (MF_GRAYED|MF_DISABLED|MF_SEPARATOR)))) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 		mnis.lpItemData = (LPSTR)&rcRect;
@@ -289,11 +289,11 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		pt.y = rcRect.bottom - 1;
 		ClientToScreen(hWnd,&pt);
 		SetRect(&rcRect,pt.x,pt.y,0,0);
-		RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		RELEASELBOXINFO(hMenu32);
 		return CreatePopup(hWnd,lptps,(HMENU)(UINT)wItemID,wSel,&rcRect,TRUE);
 	    }
 	    else {
-		RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		RELEASELBOXINFO(hMenu32);
 
 		ClientToScreen(hWnd,&pt);
 		/*nPopupHit = PopupHitTest(lptps->hPopups,lptps->nPopups,pt);*/
@@ -331,7 +331,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			(wItemID == GetWindowID(hWndTmp))) {
 			SendMessage(hWndTmp,LB_SETCURSEL,
 					(WPARAM)-1,0L);
-			RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			RELEASELBOXINFO(hPopupMenu32);
 			return TRUE;
 		    }
 		    for (n = lptps->nPopups-1; n>nPopupHit; n--) 
@@ -343,7 +343,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			}
 		    if (!((lFlags & MF_POPUP) &&
 			!(lFlags & (MF_GRAYED|MF_DISABLED|MF_SEPARATOR)))) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+		        RELEASELBOXINFO(hPopupMenu32);
 			return TRUE;
 		    }
 		    mnis.wAction = LCA_GET|LCA_RECT;
@@ -357,7 +357,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    ClientToScreen(hPopup,&pt);
 		    SetRect(&rcRect,pt.x,pt.y,0,0);
 
-		    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+		    RELEASELBOXINFO(hPopupMenu32);
 		    return CreatePopup(hWnd,lptps,(HMENU)(UINT)wItemID,
 					wSel,&rcRect,TRUE);
 		}
@@ -408,10 +408,10 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 
 		if (wPrevSel == (WORD)-1) {
 		    if (wSel == (WORD)-1) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return TRUE;
 		    } else if (!(lptps->uiFlags & LSF_CAPTUREACTIVE))  {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return InternalMenuProc(hWnd,uiMsg,wParam,lParam);
 		    }
 		}
@@ -419,7 +419,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,wSel);
 		if (wSel == (WORD)-1) {
 		    SetWindowWord(hWnd,TP_STATUS,1);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 
@@ -449,12 +449,12 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			pt.y = rcRect.bottom - 1;
 			ClientToScreen(hWnd,&pt);
 			SetRect(&rcRect,pt.x,pt.y,0,0);
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 
 			return CreatePopup(hWnd,lptps,(HMENU)(UINT)wItemID,
 					wSel,&rcRect,TRUE);
 		    }
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 		else {	/*  if (wSel == wPrevSel) => toggle selection */
@@ -474,7 +474,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,-1);
 		    SetWindowWord(hWnd,TP_STATUS,1);
 		    lptps->uiFlags |= PSF_POPSELKILLED;
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 	    }
@@ -496,7 +496,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 						(WORD)-1);
 		    }
 		    SetWindowWord(hWnd,TP_STATUS,1);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 
@@ -538,7 +538,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 					lptps->hMenu));
 		    if (!(lFlags & MF_POPUP) ||
 			    (lFlags & (MF_GRAYED|MF_DISABLED|MF_SEPARATOR))) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return TRUE;
 		    }
 
@@ -551,7 +551,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 				(WPARAM)-1,0L);
 
 			lptps->wPopupFlags[nPopupHit] |= PSF_POPSELKILLED;
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			RELEASELBOXINFO(hMenu32);
 			return TRUE;
 		    }
 
@@ -565,8 +565,8 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    pt.y = rcRect.top;
 		    ClientToScreen(hPopup,&pt);
 		    SetRect(&rcRect,pt.x,pt.y,0,0);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+		    RELEASELBOXINFO(hMenu32);
+		    RELEASELBOXINFO(hPopupMenu32);
 		    return CreatePopup(hWnd,lptps,(HMENU)(UINT)wItemID,wSel,&rcRect,TRUE);
 		}
 	    }
@@ -605,7 +605,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,wSel);
 		if (wSel == (WORD)-1) {
 		    SetWindowWord(hWnd,TP_STATUS,1);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		}
 		else {
@@ -613,7 +613,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,(WORD)-1);
 			SetWindowWord(hWnd,TP_STATUS,1);
 			lptps->uiFlags &= ~PSF_POPSELKILLED;
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    mnis.wPosition = wSel;
@@ -636,13 +636,13 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			    PostMessage(lptps->hWndOwner,WM_COMMAND,
 				GET_WM_COMMAND_MPS(wItemID,0,0));
 			SetWindowWord(hWnd,TP_STATUS,1);
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    if (!(lFlags & (MF_DISABLED|MF_GRAYED)))
 			SetPopupMenuSel(lptps->hWndOwner,lptps->hPopups[0],0,
 				(lFlags & MF_SYSMENU)|MF_MOUSESELECT);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		}
 	    }
@@ -655,13 +655,13 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    if (!hPopup) {
 			SetWindowWord(hWnd,TP_STATUS,1);
 			ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,(WORD)-1);
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		}
 		else if (!hPopup) {
 		    if(hMenu32)
-		    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    	RELEASELBOXINFO(hMenu32);
 		    return 0;
 		}
 		ScreenToClient(hPopup,&ptScreen);
@@ -681,7 +681,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 					lptps->hPopups[nPopupHit+1],0,
 					(lFlags & MF_SYSMENU)|MF_MOUSESELECT);
 		    if(hMenu32)
-		      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		      RELEASELBOXINFO(hMenu32);
 		    return TRUE;
 		}
 		SendMessage(hPopup,uiMsg,wParam,
@@ -720,11 +720,11 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 					GET_WM_COMMAND_MPS(wItemID,0,0));
 			SetWindowWord(hWnd,TP_STATUS,1);
 		    }
-		    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);		    
+		    RELEASELBOXINFO(hPopupMenu32);		    
 		}
 	    }
 	    if(hMenu32)
-	    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    	RELEASELBOXINFO(hMenu32);
 	    return 0;
 
 	case WM_LBUTTONDBLCLK:
@@ -742,7 +742,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		pt.y = (int)((signed short)HIWORD(lParam));
 		GetClientRect(hWnd, &rcRect);
 		if (!PtInRect(&rcRect,pt)) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		}
 		wSel = MenuHitTest(hMenu32,&pt);
@@ -751,20 +751,20 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		mnis.wAction = LCA_GET | LCA_FLAGS;
 		lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mnis);
 		if (!(lFlags & (MF_POPUP|MF_BITMAP))) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return FALSE;
 		}
 		mnis.wAction = LCA_GET|LCA_ITEMID;
 		mnis.wPosition = wSel;
 		wItemID = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mnis);
 		if (!(hPopupMenu32 = GETMENUINFO(wItemID))) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return FALSE;
 		}
 		hPopupMenu32a = TWIN_FindMenuItem(hPopupMenu32,(WORD)SC_CLOSE);
 		if (hPopupMenu32a) {
 		    if (hPopupMenu32a != hPopupMenu32)
-		      RELEASELBOXINFO((LPLISTBOXINFO) hPopupMenu32a);
+		      RELEASELBOXINFO(hPopupMenu32a);
 		    lptps->uiFlags &= ~LSF_BUTTONDOWN;
 		    ChangeMBSelection(hWnd,hMenu32,lptps,wSel,(WORD)-1);
 		    SetWindowWord(hWnd,TP_STATUS,1);
@@ -774,12 +774,12 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    else
 			PostMessage(lptps->hWndOwner,WM_COMMAND,
 				GET_WM_COMMAND_MPS(SC_CLOSE,0,0));
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+		    RELEASELBOXINFO(hMenu32);
+		    RELEASELBOXINFO(hPopupMenu32);
 		    return TRUE;
 		}
 		else {
-		  RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		  RELEASELBOXINFO(hMenu32);
 		  return FALSE;
 		}
 	    }
@@ -791,10 +791,10 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    PostMessage(lptps->hWndOwner,WM_SYSCOMMAND,
 				(WPARAM)SC_CLOSE,lParam);
 		SetWindowWord(hWnd,TP_STATUS,1);
-		RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		RELEASELBOXINFO(hMenu32);
 		return TRUE;
 	    }
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return 0;
 
 	case MM_MENUINIT:
@@ -815,7 +815,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 	    if (lptps->bSystemMenu)
 		lFlags |= MF_SYSMENU;
 	    if (lFlags < 0) {
-	        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	        RELEASELBOXINFO(hMenu32);
 		return 1;
 	    }
 	    ChangeMBSelection(hWnd,hMenu32,lptps,(WORD)-1,wSel);
@@ -834,7 +834,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    PostMessage(lptps->hWndOwner,WM_COMMAND,
 				GET_WM_COMMAND_MPS(wItemID,0,0));
 		SetWindowWord(hWnd,TP_STATUS,1);
-		RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		RELEASELBOXINFO(hMenu32);
 		return 0;
 	    }
 	    mnis.lpItemData = (LPSTR)&rcRect;
@@ -847,7 +847,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 	    if (CreatePopup(hWnd,lptps,(HMENU)(UINT)wItemID,wSel,&rcRect,TRUE))
 		SetPopupMenuSel(lptps->hWndOwner,
 			lptps->hPopups[0],0,lFlags & MF_SYSMENU);
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return 0;
 
 	case WM_CHAR:
@@ -866,14 +866,14 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		hPopupMenu = (HMENU)GetWindowID(hPopup);
 		hPopupMenu32 = GETMENUINFO(hPopupMenu);
 		if (!hPopupMenu32) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 1;
 		}
-		RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		RELEASELBOXINFO(hMenu32);
 		hMenu32 = hPopupMenu32;
 	    }
 	    else if (!(lptps->uiFlags & TP_MENUBAR)) {
-	            RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	            RELEASELBOXINFO(hMenu32);
 		    return 1;
 	    }
 	    mnis.wAction = LCA_ITEMCOUNT;
@@ -912,7 +912,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    ChangeMBSelection(hWnd,hMenu32,lptps,wPrevSel,wSel);
 		    if (lFlags & (MF_GRAYED|MF_DISABLED))
 			return 0;
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    mnis.lpItemData = (LPSTR)&rcRect;
 		    mnis.wAction = LCA_GET|LCA_RECT;
 		    LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mnis);
@@ -941,7 +941,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 	    }
 	    else {
 		if (lFlags & (MF_GRAYED|MF_DISABLED)) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		}
 		if (lFlags & MF_POPUP) {
@@ -977,7 +977,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 				GET_WM_COMMAND_MPS(wItemID,0,0));
 		}
 	    }
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return 0;
 
 	case WM_KEYDOWN:
@@ -993,7 +993,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		case VK_LEFT:
 		case VK_RIGHT:
 		    if (!(lptps->uiFlags & TP_MENUBAR)) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    if ((lptps->nPopups > 1) && (wParam == VK_LEFT)) {
@@ -1021,8 +1021,8 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			SendMessage(lptps->hWndOwner,WM_MENUSELECT,
 				GET_WM_MENUSELECT_MPS(wItemID,LOWORD(lFlags),
 							hMenu));
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-			RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			RELEASELBOXINFO(hMenu32);
+			RELEASELBOXINFO(hPopupMenu32);
 			return 0;
 		    }
 		    if (lptps->nPopups && (wParam == VK_RIGHT)) {
@@ -1060,8 +1060,8 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 				SetPopupMenuSel(lptps->hWndOwner,
 					lptps->hPopups[lptps->nPopups-1],
 					0,lFlags & MF_SYSMENU);
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-			    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			    RELEASELBOXINFO(hMenu32);
+			    RELEASELBOXINFO(hPopupMenu32);
 			    return 0;
 			}
 			/* else -- fall through */
@@ -1070,7 +1070,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    mnis.wAction = LCA_SELECTION;
 		    wPrevSel = (WORD)LBoxAPI(hMenu32,LBA_GETDATA,(LPARAM)&mnis);
 		    if (wPrevSel == (WORD)-1) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    mnis.wAction = LCA_ITEMCOUNT;
@@ -1095,7 +1095,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			GET_WM_MENUSELECT_MPS(wItemID,LOWORD(lFlags),hMenu));
 		    if (!((lFlags & MF_POPUP) &&
 			!(lFlags & (MF_GRAYED|MF_DISABLED|MF_SEPARATOR)))) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    mnis.lpItemData = (LPSTR)&rcRect;
@@ -1109,19 +1109,19 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 					&rcRect,TRUE))
 			SetPopupMenuSel(lptps->hWndOwner,lptps->hPopups[0],
 					0,lFlags & MF_SYSMENU);
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		case VK_RETURN:
 		    mnis.wPosition = (WORD)-1;
 		    mnis.wAction = LCA_GET|LCA_SELECTION;
 		    wPrevSel = (WORD)LBoxAPI(hMenu32,LBA_GETDATA,(LPARAM)&mnis);
 		    if (wPrevSel == (WORD)-1) {
-		        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		        RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    if (lptps->nPopups == 0) {	/* item on menubar */
 			if (!(lptps->uiFlags & TP_MENUBAR)) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			    RELEASELBOXINFO(hMenu32);
 			    return 0;
 			}
 			mnis.wPosition = wPrevSel;
@@ -1131,7 +1131,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			if (lptps->bSystemMenu)
 			    lFlags |= MF_SYSMENU;
 			if (lFlags & (MF_GRAYED|MF_DISABLED)) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			    RELEASELBOXINFO(hMenu32);
 			    return 0;
 			}
 			mnis.wAction = LCA_GET|LCA_ITEMID;
@@ -1171,8 +1171,8 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			hPopupMenu32 = GETMENUINFO(hPopupMenu);
 			wSel = (WORD)SendMessage(hPopup,LB_GETCURSEL,0,0L);
 			if (wSel == (WORD)LB_ERR) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-			    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			    RELEASELBOXINFO(hMenu32);
+			    RELEASELBOXINFO(hPopupMenu32);
 			    return 0;
 			}
 			mnis.wPosition = wSel;
@@ -1202,7 +1202,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 				SetPopupMenuSel(lptps->hWndOwner,
 					lptps->hPopups[lptps->nPopups-1],
 					0,lFlags & MF_SYSMENU);
-			    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			    RELEASELBOXINFO(hPopupMenu32);
 			}
 			else {
 			    if (lptps->uiFlags & TP_MENUBAR)
@@ -1220,13 +1220,13 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			    }
 			}
 		    }
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		case VK_UP:
 		case VK_DOWN:
 		    if (lptps->nPopups == 0) {
 			if (!(lptps->uiFlags & TP_MENUBAR)) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			    RELEASELBOXINFO(hMenu32);
 			    return 0;
 			}
 		        mnis.wPosition = (WORD)-1;
@@ -1234,7 +1234,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		        wPrevSel = (WORD)LBoxAPI(hMenu32,LBA_GETDATA,
 					(LPARAM)&mnis);
 		        if (wPrevSel == (WORD)-1) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			    RELEASELBOXINFO(hMenu32);
 			    return 0;
 			}
 			mnis.wPosition = wSel;
@@ -1249,7 +1249,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			wItemID = (WORD)LBoxAPI(hPopupMenu32,LBA_MODIFYITEM,
 				(LPARAM)&mnis);
 			if (!(lFlags & MF_POPUP)) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			    RELEASELBOXINFO(hMenu32);
 			    /*  FIX_ME  hPopupMenu32 as well?? */
 			    return 0;
 			}
@@ -1271,8 +1271,8 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			hPopupMenu32 = GETMENUINFO(hPopupMenu);
 			wPrevSel = (WORD)SendMessage(hPopup,LB_GETCURSEL,0,0L);
 			if (wPrevSel == (WORD)LB_ERR) {
-			    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-			    RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			    RELEASELBOXINFO(hMenu32);
+			    RELEASELBOXINFO(hPopupMenu32);
 			    return 0;
 			}
 			mnis.wAction = LCA_ITEMCOUNT;
@@ -1305,9 +1305,9 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			    lFlags |= MF_SYSMENU;
 			SetPopupMenuSel(lptps->hWndOwner,hPopup,wSel,
 					lFlags & MF_SYSMENU);
-			RELEASELBOXINFO((LPLISTBOXINFO)hPopupMenu32);
+			RELEASELBOXINFO(hPopupMenu32);
 		    }
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		case VK_ESCAPE:
 		    if (lptps->nPopups) {
@@ -1332,7 +1332,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 			}
 			SetWindowWord(hWnd,TP_STATUS,1);
 		    }
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    return 0;
 		default:
 		    break;
@@ -1356,7 +1356,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 	    }
 	    hMenu32 = GETMENUINFO((HMENU)wParam);
 	    DrawPopupMenuItem(hMenu32,lptps->hWndOwner,lpdis);
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return 0L;
 
 	case WM_MEASUREITEM:
@@ -1372,12 +1372,12 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    mnis.lpItemData = (LPSTR)&rcRect;
 		    lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mnis);
 		    if (lFlags < 0) {
-			RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+			RELEASELBOXINFO(hMenu32);
 			return 0;
 		    }
 		    lpmis->itemHeight = rcRect.bottom - rcRect.top;
 		    lpmis->itemWidth = rcRect.right - rcRect.left;
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 	    }
 	    return 0L;
 
@@ -1407,7 +1407,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		mnis.wPosition = wSel;
 		lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mnis);
 		if (lFlags < 0) {
-		    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+		    RELEASELBOXINFO(hMenu32);
 		    break;
 		}
 		mnis.wAction = LCA_GET|LCA_ITEMID;
@@ -1416,7 +1416,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		if (lptps->bSystemMenu)
 		    lFlags |= MF_SYSMENU;
 
-	        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	        RELEASELBOXINFO(hMenu32);
 
 		return SendMessage(lptps->hWndOwner,WM_MENUSELECT,
 			GET_WM_MENUSELECT_MPS(wItemID,LOWORD(lFlags),wParam));
@@ -1446,7 +1446,7 @@ MenuBarProc(HWND hWnd, UINT uiMsg, WPARA
 		    wSel = (WORD)LBoxAPI(hMenu32,LBA_GETDATA,(LPARAM)&mnis);
 		    if (wSel != (WORD)-1)
 			ChangeMBSelection(hWnd,hMenu32,lptps,wSel,(WORD)-1);
-	    	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    	    RELEASELBOXINFO(hMenu32);
 		}
 	    }
 	    SetWindowWord(hWnd,TP_STATUS,1);
@@ -1527,11 +1527,11 @@ CreatePopup (HWND hWndMenu,LPTRACKPOPUPS
 		GetWindowInstance(hWndMenu),
 		(LPVOID)hMenu32)))  {
         if (hMenu32)
-	  RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	  RELEASELBOXINFO(hMenu32);
 	return FALSE;
     }
     if (hMenu32)
-      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+      RELEASELBOXINFO(hMenu32);
     lptps->nPopups++;
     SetWindowID(lptps->hPopups[n],hPopup);
     if (n > 0)
@@ -1888,7 +1888,7 @@ TranslateMenuChar(HWND hWnd, WPARAM wKey
         hWndMenu = GetWindowFrame(hWnd);
         InternalMenuProc(hWndMenu,MM_MENUINIT,(WPARAM)i,0L);
     }
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
 }
 
 static LRESULT
