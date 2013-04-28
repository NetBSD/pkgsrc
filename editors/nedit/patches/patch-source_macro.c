$NetBSD: patch-source_macro.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call XtVaCreateManagedWidget and XtVaGetValues correctly.
Silence gcc warnings about unsafe pointer casts.

--- source/macro.c~	2004-08-01 10:06:10.000000000 +0000
+++ source/macro.c
@@ -2830,7 +2830,7 @@ static int dialogMS(WindowInfo *window, 
     for (i=1; i<nBtns; i++) {
     	btn = XtVaCreateManagedWidget("mdBtn", xmPushButtonWidgetClass, dialog,
     	    	XmNlabelString, s1=XmStringCreateSimple(btnLabels[i]),
-    	    	XmNuserData, (XtPointer)(i+1), NULL);
+    	    	XmNuserData, (XtPointer)(intptr_t)(i+1), NULL);
     	XtAddCallback(btn, XmNactivateCallback, dialogBtnCB, window);
     	XmStringFree(s1);
     }
@@ -2871,7 +2871,7 @@ static void dialogBtnCB(Widget w, XtPoin
     	return; /* shouldn't happen */
     if (XtClass(w) == xmPushButtonWidgetClass) {
 	XtVaGetValues(w, XmNuserData, &userData, NULL);
-	retVal.val.n = (int)userData;
+	retVal.val.n = (intptr_t)userData;
     } else
     	retVal.val.n = 1;
     retVal.tag = INT_TAG;
@@ -3003,7 +3003,7 @@ static int stringDialogMS(WindowInfo *wi
     for (i=1; i<nBtns; i++) {
     	btn = XtVaCreateManagedWidget("mdBtn", xmPushButtonWidgetClass, dialog,
     	    	XmNlabelString, s1=XmStringCreateSimple(btnLabels[i]),
-    	    	XmNuserData, (XtPointer)(i+1), NULL);
+    	    	XmNuserData, (XtPointer)(intptr_t)(i+1), NULL);
     	XtAddCallback(btn, XmNactivateCallback, stringDialogBtnCB, window);
     	XmStringFree(s1);
     }
@@ -3057,7 +3057,7 @@ static void stringDialogBtnCB(Widget w, 
        returned in w. */
     if (XtClass(w) == xmPushButtonWidgetClass) {
 	XtVaGetValues(w, XmNuserData, &userData, NULL);
-	btnNum = (int)userData;
+	btnNum = (intptr_t)userData;
     } else
     	btnNum = 1;
     
@@ -3456,7 +3456,7 @@ static int listDialogMS(WindowInfo *wind
     for (i=1; i<nBtns; i++) {
       btn = XtVaCreateManagedWidget("mdBtn", xmPushButtonWidgetClass, dialog,
               XmNlabelString, s1=XmStringCreateSimple(btnLabels[i]),
-              XmNuserData, (XtPointer)(i+1), NULL);
+              XmNuserData, (XtPointer)(intptr_t)(i+1), NULL);
       XtAddCallback(btn, XmNactivateCallback, listDialogBtnCB, window);
       XmStringFree(s1);
     }
@@ -3536,7 +3536,7 @@ static void listDialogBtnCB(Widget w, Xt
        returned in w. */
     if (XtClass(w) == xmPushButtonWidgetClass) {
       XtVaGetValues(w, XmNuserData, &userData, NULL);
-      btnNum = (int)userData;
+      btnNum = (intptr_t)userData;
     } else
       btnNum = 1;
     
