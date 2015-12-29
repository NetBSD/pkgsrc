$NetBSD: patch-newlisp.c,v 1.3 2015/12/29 23:34:52 dholland Exp $

Fix build with recent readline.

--- newlisp.c.orig	2014-04-08 14:02:27.000000000 +0000
+++ newlisp.c
@@ -138,7 +138,7 @@ char preLoad[] = 
     "(define (Class:Class) (cons (context) (args)))";
 void printHelpText(void);
 #ifdef READLINE
-char ** newlisp_completion (char * text, int start, int end);
+char ** newlisp_completion (const char * text, int start, int end);
 #endif
 /* --------------------- globals -------------------------------------- */
 
@@ -904,8 +904,8 @@ if(errorReg && !isNil((CELL*)errorEvent-
 
 #ifdef READLINE
 rl_readline_name = "newlisp";
-rl_attempted_completion_function = (CPPFunction *)newlisp_completion;
-#if defined(LINUX) || defined(_BSD)
+rl_attempted_completion_function = newlisp_completion;
+#if defined(LINUX)
 /* in Bash .inputrc put 'set blink-matching-paren on' */
 rl_set_paren_blink_timeout(300000); /* 300 ms */
 #endif
@@ -959,7 +959,7 @@ return 0;
 #endif /* not LIBRARY */
 
 #ifdef READLINE
-char * command_generator(char * text, int state)
+char * command_generator(const char * text, int state)
 {
 static int list_index, len, clen;
 char * name;
@@ -984,15 +984,9 @@ while((name = primitive[list_index].name
 return ((char *)NULL);
 }
 
-#ifdef _BSD
-extern char **completion_matches PARAMS((char *, rl_compentry_func_t *));
-#else
-char ** completion_matches(const char * text, CPFunction commands);
-#endif
-
-char ** newlisp_completion (char * text, int start, int end)
+char ** newlisp_completion (const char * text, int start, int end)
 {
-return(completion_matches(text, (CPFunction *)command_generator));
+return(completion_matches(text, command_generator));
 }
 #endif /* READLINE */
 
