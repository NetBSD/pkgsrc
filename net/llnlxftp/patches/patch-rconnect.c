$NetBSD: patch-rconnect.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- rconnect.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ rconnect.c
@@ -61,6 +61,8 @@
 #include "list.h"
 #include "str.h"
 
+void create_rconnect_dialog(void);
+
 static struct {
     Widget w_dialog;
     Widget w_form;
@@ -154,7 +156,7 @@ XtPointer call_data;
 /*
  * create_rconnect_dialog - Creates the Remote Connection dialog.
  */
-create_rconnect_dialog()
+void create_rconnect_dialog(void)
 {
 	static int initialized = False;
 	Arg	args[2];
