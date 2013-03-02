$NetBSD: patch-rename.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- rename.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ rename.c
@@ -63,6 +63,8 @@
 #define SKIP	2
 #define CANCEL	3
 
+static void create_rename_dialog(void);
+
 static struct {
 	Widget w_dialog;
 	Widget w_form;
@@ -236,7 +238,7 @@ lost:
 /*
  * create_rename_dialog - Create dialog that prompts for new names.
  */
-create_rename_dialog()
+static void create_rename_dialog(void)
 {
 	static int initialized = False;
 	int i;
