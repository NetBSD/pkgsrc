$NetBSD: patch-newlisp.c,v 1.4 2019/04/24 13:09:45 hauke Exp $

Fix build with recent readline.

--- newlisp.c.orig	2017-01-25 16:42:21.000000000 +0000
+++ newlisp.c
@@ -138,7 +138,7 @@ char preLoad[] = 
     "(define (Class:Class) (cons (context) (args)))";
 void printHelpText(void);
 #ifdef READLINE
-char ** newlisp_completion (char * text, int start, int end);
+char ** newlisp_completion (const char * text, int start, int end);
 #endif
 /* --------------------- globals -------------------------------------- */
 
@@ -931,7 +931,7 @@ if(errorReg && !isNil((CELL*)errorEvent-
 #ifdef READLINE
 rl_readline_name = "newlisp";
 rl_attempted_completion_function = (char ** (*) (const char *, int, int))newlisp_completion;
-#if defined(LINUX) || defined(_BSD) || defined(KFREEBSD)
+#if defined(LINUX) || defined(KFREEBSD)
 /* in Bash .inputrc put 'set blink-matching-paren on' */
 rl_set_paren_blink_timeout(300000); /* 300 ms */
 #endif
@@ -985,7 +985,7 @@ return 0;
 #endif /* not LIBRARY */
 
 #ifdef READLINE
-char * command_generator(char * text, int state)
+char * command_generator(const char * text, int state)
 {
 static int list_index, len, clen;
 char * name;
@@ -1012,7 +1012,7 @@ return ((char *)NULL);
 
 char ** completion_matches(const char * text,  char * (*commands)(const char *, int)); 
 
-char ** newlisp_completion (char * text, int start, int end)
+char ** newlisp_completion (const char * text, int start, int end)
 {
 return(completion_matches(text,  (char * (*) (const char *, int) )command_generator));
 }
