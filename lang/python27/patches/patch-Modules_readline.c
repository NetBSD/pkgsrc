$NetBSD: patch-Modules_readline.c,v 1.1 2014/03/15 05:38:14 dholland Exp $

Fix py-readline build with readline 6.3.

--- Modules/readline.c~	2013-11-10 07:36:41.000000000 +0000
+++ Modules/readline.c
@@ -911,12 +911,12 @@ setup_readline(void)
     rl_bind_key_in_map ('\t', rl_complete, emacs_meta_keymap);
     rl_bind_key_in_map ('\033', rl_complete, emacs_meta_keymap);
     /* Set our hook functions */
-    rl_startup_hook = (Function *)on_startup_hook;
+    rl_startup_hook = (rl_hook_func_t *)on_startup_hook;
 #ifdef HAVE_RL_PRE_INPUT_HOOK
-    rl_pre_input_hook = (Function *)on_pre_input_hook;
+    rl_pre_input_hook = (rl_hook_func_t *)on_pre_input_hook;
 #endif
     /* Set our completion function */
-    rl_attempted_completion_function = (CPPFunction *)flex_complete;
+    rl_attempted_completion_function = (rl_completion_func_t *)flex_complete;
     /* Set Python word break characters */
     completer_word_break_characters =
         rl_completer_word_break_characters =
