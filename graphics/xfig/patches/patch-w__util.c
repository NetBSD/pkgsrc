$NetBSD: patch-w__util.c,v 1.1 2012/12/24 21:12:36 joerg Exp $

--- w_util.c.orig	2012-12-23 17:41:50.000000000 +0000
+++ w_util.c
@@ -710,7 +710,7 @@ start_spin_timer(Widget widget, XtPointe
     /* keep track of which one the user is pressing */
     cur_spin = widget;
 
-    return;
+    return 0;
 }
 
 static XtEventHandler
@@ -718,7 +718,7 @@ stop_spin_timer(int widget, int data, in
 {
     XtRemoveTimeOut(auto_spinid);
 
-    return;
+    return 0;
 }
 
 static	XtTimerCallbackProc
@@ -729,7 +729,7 @@ auto_spin(XtPointer client_data, XtInter
     /* call the proper spinup/down routine */
     XtCallCallbacks(cur_spin, XtNcallback, 0);
 
-    return;
+    return 0;
 }
 
 /***************************/
@@ -1412,7 +1412,7 @@ toggle_checkbutton(Widget w, XtPointer d
     }
     SetValues(w);
 
-    return;
+    return 0;
 }
 
 /* assemble main window title bar with xfig title and (base) file name */
