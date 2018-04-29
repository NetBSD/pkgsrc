$NetBSD: patch-editor.c,v 1.1 2018/04/29 03:56:08 dholland Exp $

Fix LP64 issue.

--- editor.c~	1996-01-30 23:36:29.000000000 +0000
+++ editor.c
@@ -801,7 +801,7 @@ XmAnyCallbackStruct *call_data;
 {
 	Editor eObject = (Editor) client_data;
 	long item_id;
-	int data_id;
+	long data_id;
 	char *buffer = "";	/* null string */
 	XmString clip_label = XmStringCreateSimple(eObject->app_name);
 
@@ -1007,7 +1007,7 @@ Time time_stamp;
 {
 	char *selection;
 	long item_id;
-	int data_id;
+	long data_id;
 	Display *dpy = XtDisplay(eObject->edit);
 	Window win = XtWindow(eObject->edit);
 	XmString clip_label = XmStringCreateSimple(eObject->app_name);
