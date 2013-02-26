$NetBSD: patch-utils_answer.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- utils/answer.c.orig	2013-02-25 16:43:08.000000000 +0000
+++ utils/answer.c
@@ -53,6 +53,7 @@ DBZ *hash;		/* dbz file for same */
 char *get_alias_address(), *get_token(), *strip_parens(), *shift_lower();
 
 static char *quit_word, *exit_word, *done_word, *bye_word;
+static void open_alias_file(void);
 
 main(argc, argv)
 int argc;
@@ -272,7 +273,7 @@ char *fullname, *name;
 }
 
 	    
-open_alias_file()
+static void open_alias_file(void)
 {
 	/** open the user alias file **/
 
