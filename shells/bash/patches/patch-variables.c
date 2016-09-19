$NetBSD: patch-variables.c,v 1.4 2016/09/19 09:06:03 wiz Exp $

Only read functions from environment if flag is set.

--- variables.c.orig	2016-06-15 20:05:52.000000000 +0000
+++ variables.c
@@ -115,6 +115,7 @@ extern time_t shell_start_time;
 extern int assigning_in_environment;
 extern int executing_builtin;
 extern int funcnest_max;
+extern int import_functions;
 
 #if defined (READLINE)
 extern int no_line_editing;
@@ -365,7 +366,7 @@ initialize_shell_variables (env, privmod
 #if defined (FUNCTION_IMPORT)
       /* If exported function, define it now.  Don't import functions from
 	 the environment in privileged mode. */
-      if (privmode == 0 && read_but_dont_execute == 0 && 
+      if (import_functions && privmode == 0 && read_but_dont_execute == 0 && 
           STREQN (BASHFUNC_PREFIX, name, BASHFUNC_PREFLEN) &&
           STREQ (BASHFUNC_SUFFIX, name + char_index - BASHFUNC_SUFFLEN) &&
 	  STREQN ("() {", string, 4))
