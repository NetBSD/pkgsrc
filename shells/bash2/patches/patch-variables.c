$NetBSD: patch-variables.c,v 1.2 2014/09/30 18:27:40 christos Exp $

Only read functions from environment if flag is set.

--- variables.c.orig	2014-09-30 14:22:56.000000000 -0400
+++ variables.c	2014-09-30 14:23:31.000000000 -0400
@@ -87,6 +87,7 @@
 extern SHELL_VAR *this_shell_function;
 extern char *this_command_name;
 extern time_t shell_start_time;
+extern int import_functions;
 
 /* The list of shell variables that the user has created at the global
    scope, or that came from the environment. */
@@ -265,7 +266,7 @@
 
       /* If exported function, define it now.  Don't import functions from
 	 the environment in privileged mode. */
-      if (privmode == 0 && read_but_dont_execute == 0 &&
+      if (import_functions && privmode == 0 && read_but_dont_execute == 0 &&
 	  STREQN (BASHFUNC_PREFIX, name, BASHFUNC_PREFLEN) &&
 	  STREQ (BASHFUNC_SUFFIX, name + char_index - BASHFUNC_SUFFLEN) &&
 	  STREQN ("() {", string, 4))
