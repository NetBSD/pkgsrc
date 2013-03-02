$NetBSD: patch-aconnect.c,v 1.1 2013/03/02 17:59:40 joerg Exp $

--- aconnect.c.orig	2013-03-01 13:50:09.000000000 +0000
+++ aconnect.c
@@ -60,6 +60,8 @@
 #include "list.h"
 #include "str.h"
 
+void create_aconnect_dialog(void);
+
 static struct {
     Widget w_dialog;
     Widget w_form;
@@ -167,7 +169,7 @@ XtPointer call_data;
 /*
  * create_aconnect_dialog - Creates the Remote Connection dialog.
  */
-create_aconnect_dialog()
+void create_aconnect_dialog(void)
 {
 	static int initialized = False;
 	Arg	args[2];
