$NetBSD: patch-windows_MenuAPI.c,v 1.1 2011/03/15 11:30:05 obache Exp $

* remove needless cast

--- windows/MenuAPI.c.orig	2001-01-13 08:47:52.000000000 +0000
+++ windows/MenuAPI.c
@@ -121,7 +121,7 @@ DestroyMenu(HMENU hMenu)
 	return FALSE;
 
     bResult = LBoxAPI(hMenu32,LBA_DESTROY,0);
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return bResult;
 }
 
@@ -170,7 +170,7 @@ ModifyMenuEx(HMENU32 hMenu32, UINT uiPos
 	    lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
 	    if (lFlags == (LONG)-1) {
 	        if (hMenu32 != hMenu32orig)
-		  RELEASELBOXINFO((LPLISTBOXINFO)hMenu32); 
+		  RELEASELBOXINFO(hMenu32); 
 		return FALSE;
 	    }
 	}
@@ -227,7 +227,7 @@ ModifyMenuEx(HMENU32 hMenu32, UINT uiPos
     mis.lpItemData = lpItem;
     rc = (BOOL)LBoxAPI(hMenu32,uiAction,(LPARAM)&mis);
     if (hMenu32 != hMenu32orig)
-      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+      RELEASELBOXINFO(hMenu32);
     return rc;
 }
 
@@ -281,7 +281,7 @@ InsertMenu(HMENU hMenu, UINT uiPosition,
 	bResult = ModifyMenuEx(hMenu32,
 			uiPosition,uiFlags,uiIDNewItem,lpNewItem,
 			LBA_INSERTITEM);
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	RELEASELBOXINFO(hMenu32);
     }
     APISTR((LF_APIRET,"InsertMenu: returns BOOL %d\n",bResult));
     return bResult;
@@ -320,7 +320,7 @@ InsertMenuItem(HMENU hMenu,UINT ItemID,B
 			lpmenuinfo->wID,   /* id or position*/
 			lpmenuinfo->dwTypeData, opcode);
 
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
 
     	APISTR((LF_APIRET,"InsertMenuItem: returns BOOL %d\n",rc));
 	return rc;
@@ -336,7 +336,7 @@ AppendMenu(HMENU hMenu, UINT uiFlags, UI
     if((hMenu32 = GETMENUINFO(hMenu))) {
     	bResult = ModifyMenuEx(hMenu32,(UINT)-1,uiFlags,uiIDNewItem,lpNewItem,
 			LBA_APPENDITEM);
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
     }
     APISTR((LF_APIRET,"AppendMenu: returns BOOL %d\n",bResult));
     return bResult;
@@ -354,7 +354,7 @@ ModifyMenu(HMENU hMenu, UINT uiPosition,
     	bResult =  ModifyMenuEx(hMenu32,
 			uiPosition,uiFlags,uiIDNewItem,lpNewItem,
 			LBA_MODIFYITEM);
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
     }
     APISTR((LF_APIRET,"ModifyMenu: returns BOOL %d\n",bResult));
     return bResult;
@@ -374,7 +374,7 @@ RemoveMenu(HMENU hMenu, UINT idItem, UIN
 		bResult = ModifyMenuEx(hMenu32,0,uiFlags,
 				idItem,NULL,LBA_REMOVEITEM);
 	}
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	RELEASELBOXINFO(hMenu32);
     }
     return bResult;
 }
@@ -393,7 +393,7 @@ DeleteMenu(HMENU hMenu, UINT idItem, UIN
         	bResult =  ModifyMenuEx(hMenu32,0,
 				uiFlags,idItem,NULL, LBA_DELETEITEM);
 	}
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	RELEASELBOXINFO(hMenu32);
     }
     return bResult;
 }
@@ -452,7 +452,7 @@ ChangeMIFlags(HMENU32 hMenu32, UINT uiIt
 	lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
 	if (lFlags < 0) {
 	    if (hMenu32 != hMenu32orig)
-	      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	      RELEASELBOXINFO(hMenu32);
 	    return -1;
 	}
     }
@@ -470,11 +470,11 @@ ChangeMIFlags(HMENU32 hMenu32, UINT uiIt
     mis.wAction = LCA_SET | LCA_FLAGS;
     if (LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis) < 0) {
         if (hMenu32 != hMenu32orig)
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	return -1;
     }
     if (hMenu32 != hMenu32orig)
-      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+      RELEASELBOXINFO(hMenu32);
     return (LOWORD(lFlags) & uiMask);
 }
 	
@@ -489,7 +489,7 @@ EnableMenuItem(HMENU hMenu, UINT uiIDEna
     if(hMenu32) {
 	retcode = (BOOL)ChangeMIFlags(hMenu32,
 		uiIDEnableItem, uiEnable,MF_DISABLED);
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	RELEASELBOXINFO(hMenu32);
     }
     return retcode;
 }
@@ -504,7 +504,7 @@ CheckMenuItem(HMENU hMenu, UINT uiIDChec
     if(hMenu32) {
     	rc = (BOOL)ChangeMIFlags(hMenu32, 
 		uiIDCheckItem,uiCheck,MF_CHECKED);
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
     }
     return rc;
 }
@@ -519,7 +519,7 @@ HiliteMenuItem(HWND hWnd, HMENU hMenu, U
     if(hMenu32) {
     	bResult = (BOOL)ChangeMIFlags(hMenu32, 
 	       uiIDHiliteItem,uiHilite,MF_HILITE);
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
     }
     return bResult;
 }
@@ -798,7 +798,7 @@ CalcPopupMenuDimensions(HMENU hMenu, HWN
     WinFree((LPSTR)lpItemHeights);
     WinFree((LPSTR)lpColumnData);
 
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
 
     return MAKELONG((WORD)nMenuWidth,(WORD)nMenuHeight);
 }
@@ -916,7 +916,7 @@ DrawMenuBar(HWND hWnd)
 #endif
 
     ReleaseDC(hWndMenu,hDC);
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
 }
 
 WORD
@@ -1044,7 +1044,7 @@ MeasureWindowMenu(HWND hWnd, HWND hWndMe
     }
 
     ReleaseDC(hWndMenu,hDC);
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return ((wLine+1)*wItemHeight + 1);
 }
 
@@ -1174,12 +1174,12 @@ SetMenu(HWND hWnd, HMENU hMenu)
 
     if (hMenu == SetWindowMenu(hWnd, hMenu)) {
 	if(hMenu32)
-        	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+        	RELEASELBOXINFO(hMenu32);
 	return TRUE;
     }
     if (!(hWndMenu = GetWindowFrame(hWnd))) {
 	if(hMenu32)
-        	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+        	RELEASELBOXINFO(hMenu32);
 	return FALSE;
     }
 
@@ -1191,13 +1191,13 @@ SetMenu(HWND hWnd, HMENU hMenu)
 	    lptps = 0;
 	}
 	//no free required, hMenu == 0
-	//RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	//RELEASELBOXINFO(hMenu32);
 	//return TRUE;
     }
     else if (lptps == NULL) {
 	lptps = (LPTRACKPOPUPSTRUCT)WinMalloc(sizeof(TRACKPOPUPSTRUCT));
 	if (!lptps) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return FALSE;
 	}
 	memset((LPSTR)lptps,'\0',sizeof(TRACKPOPUPSTRUCT));
@@ -1214,7 +1214,7 @@ SetMenu(HWND hWnd, HMENU hMenu)
     TWIN_RedrawWindow(hWnd,NULL,0,RDW_FRAME|RDW_INVALIDATE);
 
     if(hMenu32)
-    	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    	RELEASELBOXINFO(hMenu32);
 
     return TRUE;
 }
@@ -1254,7 +1254,7 @@ GetSubMenu(HMENU hMenu, int nPos)
     mis.wAction = LCA_GET | LCA_ITEMID;
     uiItemID = (UINT)LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
 
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
 
     if (IsMenu((HMENU)uiItemID))
 	return (HMENU)uiItemID;
@@ -1277,7 +1277,7 @@ GetMenuItemCount(HMENU hMenu)
     mis.wPosition = (WORD)-1;
     nCount = (int)LBoxAPI(hMenu32,LBA_GETDATA,(LPARAM)&mis);
 
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return nCount;
 }
 
@@ -1302,7 +1302,7 @@ GetMenuItemID(HMENU hMenu, int nPos)
     mis.wAction = LCA_GET | LCA_ITEMID;
     rc = (UINT)LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
 
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return rc;
 }
 
@@ -1325,30 +1325,30 @@ GetMenuString(HMENU hMenu, UINT uiIDItem
     lpItemString = (LPSTR)LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
     if (((LONG)lpItemString != (LONG)-1) && HIWORD(lpItemString)) {
 	strncpy(lpString,lpItemString,nMaxCount);
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	RELEASELBOXINFO(hMenu32);
 	return strlen(lpString);
     }
 
     if (lpItemString == NULL || !HIWORD(lpItemString)) {
-        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+        RELEASELBOXINFO(hMenu32);
 	return 0;
     }
 
     if (uiFlags & MF_BYPOSITION) {
-        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+        RELEASELBOXINFO(hMenu32);
 	return 0;
     }
 
     hMenu32a = TWIN_FindMenuItem(hMenu32,uiIDItem);
     if (!hMenu32a) {
-        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+        RELEASELBOXINFO(hMenu32);
         return 0;
     }
     hMenu = ((LPOBJHEAD)hMenu32a)->hObj;
     if (hMenu32a != hMenu32)
-      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32a);
+      RELEASELBOXINFO(hMenu32a);
 
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return GetMenuString(hMenu,uiIDItem,lpString,nMaxCount,uiFlags);
 }
 
@@ -1370,22 +1370,22 @@ GetMenuItemData(HMENU hMenu, UINT uiItem
     lpItemData = (LPSTR)LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
     if (lpItemData == (LPSTR)-1) {
 	if (uiFlags & MF_BYPOSITION) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return lpItemData;
 	}
 	hMenu32a = TWIN_FindMenuItem(hMenu32,uiItem);
 	if (!hMenu32a) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return lpItemData;
 	}
 	hMenu = ((LPOBJHEAD)hMenu32a)->hObj;
 	if (hMenu32a != hMenu32) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32a);
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32a);
+	    RELEASELBOXINFO(hMenu32);
 	    return GetMenuItemData(hMenu,uiItem,uiFlags);
 	}
     }
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return lpItemData;
 }
 
@@ -1408,24 +1408,24 @@ GetMenuState(HMENU hMenu, UINT uiID, UIN
 
         HMENU32 hMenu32orig = hMenu32;
 	if (uiFlags & MF_BYPOSITION) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return (UINT)-1;
 	}
 
 	hMenu32 = TWIN_FindMenuItem(hMenu32,uiID);
 
 	if (!hMenu32) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+	    RELEASELBOXINFO(hMenu32orig);
 	    return (UINT)-1;
 	}
 	hMenu = ((LPOBJHEAD)hMenu32)->hObj;
 	if (hMenu32 != hMenu32orig)
-	  RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	  RELEASELBOXINFO(hMenu32);
 
-	RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+	RELEASELBOXINFO(hMenu32orig);
 	return GetMenuState(hMenu,uiID,uiFlags);
     }
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+    RELEASELBOXINFO(hMenu32);
     return (UINT)(lFlags & ~MF_BYPOSITION);
 }
 
@@ -1449,20 +1449,20 @@ SetMenuItemBitmaps(HMENU hMenu, UINT uiI
     lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
     if (lFlags < 0) { 
 	if (uiFlags & MF_BYPOSITION)  {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
+	    RELEASELBOXINFO(hMenu32);
 	    return FALSE;
 	}
 	hMenu32 = TWIN_FindMenuItem(hMenu32,uiItem);
 	if (!hMenu32) {
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+	    RELEASELBOXINFO(hMenu32orig);
 	    return FALSE;
 	}
 	mis.wAction = LCA_GET|LCA_FLAGS;
 	lFlags = LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis);
 	if (lFlags < 0) {
 	    if (hMenu32 != hMenu32orig)
-	      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-	    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+	      RELEASELBOXINFO(hMenu32);
+	    RELEASELBOXINFO(hMenu32orig);
 	    return FALSE;
 	}
 	mis.wItemFlags = MF_BYPOSITION;
@@ -1472,13 +1472,13 @@ SetMenuItemBitmaps(HMENU hMenu, UINT uiI
     mis.wAction = LCA_SET | LCA_BITMAPS;
     if (LBoxAPI(hMenu32,LBA_MODIFYITEM,(LPARAM)&mis) < 0) {
         if (hMenu32 != hMenu32orig)
-	  RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-        RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+	  RELEASELBOXINFO(hMenu32);
+        RELEASELBOXINFO(hMenu32orig);
 	return FALSE;
     }
     if (hMenu32 != hMenu32orig)
-      RELEASELBOXINFO((LPLISTBOXINFO)hMenu32);
-    RELEASELBOXINFO((LPLISTBOXINFO)hMenu32orig);
+      RELEASELBOXINFO(hMenu32);
+    RELEASELBOXINFO(hMenu32orig);
     return TRUE;
 }
 
