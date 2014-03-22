$NetBSD: patch-vtysh_vtysh.c,v 1.1 2014/03/22 10:48:20 wiedi Exp $
Fix build failure with readline-6.3
patch by Matthias Klose for Ubuntu

--- vtysh/vtysh.c.orig	2013-07-30 14:47:01.000000000 +0000
+++ vtysh/vtysh.c
@@ -2211,9 +2211,9 @@ void
 vtysh_readline_init (void)
 {
   /* readline related settings. */
-  rl_bind_key ('?', (Function *) vtysh_rl_describe);
+  rl_bind_key ('?', (rl_command_func_t *) vtysh_rl_describe);
   rl_completion_entry_function = vtysh_completion_entry_function;
-  rl_attempted_completion_function = (CPPFunction *)new_completion;
+  rl_attempted_completion_function = (rl_completion_func_t *)new_completion;
   /* do not append space after completion. It will be appended
    * in new_completion() function explicitly. */
   rl_completion_append_character = '\0';
