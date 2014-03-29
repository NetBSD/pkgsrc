$NetBSD: patch-ext_readline_readline.c,v 1.1 2014/03/29 01:23:58 taca Exp $

* Don't use legacy type of readline.

--- ext/readline/readline.c.orig	2013-10-29 03:09:00.000000000 +0000
+++ ext/readline/readline.c
@@ -1974,7 +1974,7 @@ Init_readline()
 
     rl_attempted_completion_function = readline_attempted_completion_function;
 #if defined(HAVE_RL_PRE_INPUT_HOOK)
-    rl_pre_input_hook = (Function *)readline_pre_input_hook;
+    rl_pre_input_hook = (rl_hook_func_t *)readline_pre_input_hook;
 #endif
 #ifdef HAVE_RL_CATCH_SIGNALS
     rl_catch_signals = 0;
