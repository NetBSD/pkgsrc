$NetBSD: patch-source_search.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call XtVaGetValues correctly.

--- source/search.c~	2004-08-01 10:06:11.000000000 +0000
+++ source/search.c
@@ -1042,7 +1042,7 @@ void CreateReplaceDlog(Widget parent, Wi
     XtAddCallback(replaceBtn, XmNactivateCallback, (XtCallbackProc)replaceCB, window);
     XmStringFree(st1);
     XtManageChild(replaceBtn);
-    XtVaGetValues(replaceBtn, XmNshadowThickness, &shadowThickness, 0);
+    XtVaGetValues(replaceBtn, XmNshadowThickness, &shadowThickness, (char *)NULL);
     defaultBtnOffset = shadowThickness + 4;
 	
     argcnt = 0;
