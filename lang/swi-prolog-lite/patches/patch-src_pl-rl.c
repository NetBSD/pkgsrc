$NetBSD: patch-src_pl-rl.c,v 1.1 2014/04/16 21:03:51 joerg Exp $

--- src/pl-rl.c.orig	2014-04-16 20:47:02.000000000 +0000
+++ src/pl-rl.c
@@ -93,7 +93,6 @@ extern void add_history(char *);	/* shou
 					/* readline.h versions */
 extern int rl_begin_undo_group(void);	/* delete when conflict arrises! */
 extern int rl_end_undo_group(void);
-extern Function *rl_event_hook;
 #ifndef HAVE_RL_FILENAME_COMPLETION_FUNCTION
 #define rl_filename_completion_function filename_completion_function
 extern char *filename_completion_function(const char *, int);
