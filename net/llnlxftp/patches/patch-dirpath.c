$NetBSD: patch-dirpath.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- dirpath.c.orig	1995-10-19 15:20:21.000000000 +0000
+++ dirpath.c
@@ -58,6 +58,9 @@
 #include <Xm/Form.h>
 #include "xftp.h"
 
+static void create_dirpath_dialog(int host);
+void update_dirpath(int host);
+
 static struct {
 	Widget w_dialog;
 	Widget w_form;
@@ -108,8 +111,7 @@ XtPointer call_data;
  * create_dirpath_dialog - Create dialog window that displays full
  *                         directory path name.
  */
-create_dirpath_dialog(host)
-int host;
+static void create_dirpath_dialog(int host)
 {
 	Arg args[1];
 	XmString label;
@@ -187,8 +189,7 @@ int host;
 /*
  * update_dirpath - Update contents of directory path dialog.
  */
-update_dirpath(host)
-int host;
+void update_dirpath(int host)
 {
 	XmString string;
 
