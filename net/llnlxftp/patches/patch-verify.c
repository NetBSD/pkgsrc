$NetBSD: patch-verify.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- verify.c.orig	1995-10-19 15:20:25.000000000 +0000
+++ verify.c
@@ -60,6 +60,8 @@
 #define YES     1
 #define NO      2
 
+void create_verify_dialog(void);
+
 struct verify_struct {
 	Widget w_dialog;
 	Widget w_form;
@@ -130,7 +132,7 @@ char *question;
 /*
  * create_verify_dialog - Create selection verification dialog.
  */
-create_verify_dialog()
+void create_verify_dialog(void)
 {
 	static int initialized = False;
 	Arg args[2];
