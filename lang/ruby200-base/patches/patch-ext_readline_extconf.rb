$NetBSD: patch-ext_readline_extconf.rb,v 1.1 2014/03/30 00:17:57 taca Exp $

* Handle rl_hook_func_t old/new GNU readline and editline(3).

--- ext/readline/extconf.rb.orig	2013-02-01 05:37:29.000000000 +0000
+++ ext/readline/extconf.rb
@@ -19,6 +19,10 @@ def readline.have_func(func)
   return super(func, headers)
 end
 
+def readline.have_type(type)
+  return super(type, headers)
+end
+
 dir_config('curses')
 dir_config('ncurses')
 dir_config('termcap')
@@ -93,4 +97,11 @@ readline.have_func("remove_history")
 readline.have_func("clear_history")
 readline.have_func("rl_redisplay")
 readline.have_func("rl_insert_text")
+unless readline.have_type("rl_hook_func_t")
+  # rl_hook_func_t is available since readline-4.2 (2001).
+  # Function is removed at readline-6.3 (2014).
+  # However, editline (NetBSD 6.1.3, 2014) doesn't have rl_hook_func_t.
+  $defs << "-Drl_hook_func_t=Function"
+end
+
 create_makefile("readline")
