$NetBSD: patch-qidialogs.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- qidialogs.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ qidialogs.c
@@ -57,6 +57,9 @@
 #define YES     1
 #define NO      2
 
+static void create_question_dialog(void);
+static void create_info_dialog(void);
+
 static int info_response;
 static int question_response;
 static Widget w_question;
@@ -107,7 +110,7 @@ char *question;
 /*
  * create_question_dialog - Create dialog window to ask user question.
  */
-create_question_dialog()
+static void create_question_dialog(void)
 {
 	static int initialized = False;
     Arg args[1];
@@ -193,7 +196,7 @@ char *information;
 /*
  * create_info_dialog - Create the information dialog.
  */
-create_info_dialog()
+static void create_info_dialog(void)
 {
 	static int initialized = False;
 	Arg args[1];
