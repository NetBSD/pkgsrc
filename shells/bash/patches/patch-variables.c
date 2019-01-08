$NetBSD: patch-variables.c,v 1.5 2019/01/08 16:24:42 ryoon Exp $

Only read functions from environment if flag is set.

--- variables.c.orig	2018-12-18 16:07:21.000000000 +0000
+++ variables.c
@@ -95,6 +95,7 @@
 #define FV_SKIPINVISIBLE	0x02
 
 extern char **environ;
+extern int import_functions;
 
 /* Variables used here and defined in other files. */
 extern time_t shell_start_time;
@@ -368,7 +369,7 @@ initialize_shell_variables (env, privmod
 #if defined (FUNCTION_IMPORT)
       /* If exported function, define it now.  Don't import functions from
 	 the environment in privileged mode. */
-      if (privmode == 0 && read_but_dont_execute == 0 && 
+      if (import_functions && privmode == 0 && read_but_dont_execute == 0 && 
           STREQN (BASHFUNC_PREFIX, name, BASHFUNC_PREFLEN) &&
           STREQ (BASHFUNC_SUFFIX, name + char_index - BASHFUNC_SUFFLEN) &&
 	  STREQN ("() {", string, 4))
