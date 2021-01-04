$NetBSD: patch-variables.c,v 1.6 2021/01/04 10:39:23 wiz Exp $

Only read functions from environment if flag is set.

--- variables.c.orig	2020-09-07 20:41:51.000000000 +0000
+++ variables.c
@@ -97,6 +97,7 @@
 #define FV_NODYNAMIC		0x04
 
 extern char **environ;
+extern int import_functions;
 
 /* Variables used here and defined in other files. */
 extern time_t shell_start_time;
@@ -377,7 +378,7 @@ initialize_shell_variables (env, privmod
 #if defined (FUNCTION_IMPORT)
       /* If exported function, define it now.  Don't import functions from
 	 the environment in privileged mode. */
-      if (privmode == 0 && read_but_dont_execute == 0 && 
+      if (import_functions && privmode == 0 && read_but_dont_execute == 0 && 
           STREQN (BASHFUNC_PREFIX, name, BASHFUNC_PREFLEN) &&
           STREQ (BASHFUNC_SUFFIX, name + char_index - BASHFUNC_SUFFLEN) &&
 	  STREQN ("() {", string, 4))
