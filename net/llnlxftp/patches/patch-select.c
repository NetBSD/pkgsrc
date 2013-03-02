$NetBSD: patch-select.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- select.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ select.c
@@ -65,6 +65,8 @@
 #include "list.h"
 #include "str.h"
 
+static void create_wildcard_dialog(void);
+
 static struct {
 	Widget w_dialog;
 	Widget w_form;
@@ -220,7 +222,7 @@ XtPointer call_data;
 /*
  * create_wildcard_dialog - Create dialog that prompts for wildcard.
  */
-create_wildcard_dialog()
+static void create_wildcard_dialog(void)
 {
 	static int initialized = False;
     int i;
