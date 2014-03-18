$NetBSD: patch-lib_readline.c,v 1.1 2014/03/18 03:35:23 taca Exp $

Use modern type definition of readline library.

--- lib/readline.c.orig	2013-07-24 18:53:49.000000000 +0000
+++ lib/readline.c
@@ -148,7 +148,7 @@ char *smb_readline(const char *prompt, v
 
 #if HAVE_DECL_RL_EVENT_HOOK
 	if (callback)
-		rl_event_hook = (Function *)callback;
+		rl_event_hook = (rl_hook_func_t *)callback;
 #endif
 	ret = readline(prompt);
 	if (ret && *ret)
