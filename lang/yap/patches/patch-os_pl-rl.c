$NetBSD: patch-os_pl-rl.c,v 1.2 2015/12/29 23:34:57 dholland Exp $

Fix build with readline 6.3.

--- os/pl-rl.c.orig	2014-04-20 18:59:41.000000000 +0000
+++ os/pl-rl.c
@@ -103,7 +103,6 @@ extern void add_history(char *);	/* shou
 					/* readline.h versions */
 extern int rl_begin_undo_group(void);	/* delete when conflict arrises! */
 extern int rl_end_undo_group(void);
-extern Function *rl_event_hook;
 #ifndef HAVE_RL_FILENAME_COMPLETION_FUNCTION
 #define rl_filename_completion_function filename_completion_function
 extern char *filename_completion_function(const char *, int);
