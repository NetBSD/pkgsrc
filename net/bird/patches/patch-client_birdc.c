$NetBSD: patch-client_birdc.c,v 1.1 2014/04/17 20:28:12 joerg Exp $

--- client/birdc.c.orig	2014-04-17 14:34:45.000000000 +0000
+++ client/birdc.c
@@ -29,7 +29,6 @@ static int prompt_active;
 /* HACK: libreadline internals we need to access */
 extern int _rl_vis_botlin;
 extern void _rl_move_vert(int);
-extern Function *rl_last_func;
 
 static void
 add_history_dedup(char *cmd)
