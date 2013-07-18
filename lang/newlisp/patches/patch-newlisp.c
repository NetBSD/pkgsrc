$NetBSD: patch-newlisp.c,v 1.1 2013/07/18 12:03:52 joerg Exp $

--- newlisp.c.orig	2013-07-18 09:58:06.000000000 +0000
+++ newlisp.c
@@ -886,7 +886,7 @@ if(errorReg && !isNil((CELL*)errorEvent-
 #ifdef READLINE
 rl_readline_name = "newlisp";
 rl_attempted_completion_function = (CPPFunction *)newlisp_completion;
-#if defined(LINUX) || defined(_BSD)
+#if defined(LINUX)
 /* in Bash .inputrc put 'set blink-matching-paren on' */
 rl_set_paren_blink_timeout(300000); /* 300 ms */
 #endif
@@ -965,11 +965,7 @@ while((name = primitive[list_index].name
 return ((char *)NULL);
 }
 
-#ifdef _BSD
-extern char **completion_matches PARAMS((char *, rl_compentry_func_t *));
-#else
 char ** completion_matches(const char * text, CPFunction commands);
-#endif
 
 char ** newlisp_completion (char * text, int start, int end)
 {
