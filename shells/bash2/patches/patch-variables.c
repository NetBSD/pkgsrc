$NetBSD: patch-variables.c,v 1.1 2014/09/27 03:00:06 christos Exp $

Only read functions from environment if flag is set.

--- variables.c.orig	2014-09-26 22:45:02.000000000 -0400
+++ variables.c	2014-09-26 22:54:31.000000000 -0400
@@ -82,6 +82,7 @@
 extern SHELL_VAR *this_shell_function;
 extern char *this_command_name;
 extern time_t shell_start_time;
+extern int import_functions;
 
 /* The list of shell variables that the user has created at the global
    scope, or that came from the environment. */
@@ -260,7 +261,7 @@
 
       /* If exported function, define it now.  Don't import functions from
 	 the environment in privileged mode. */
-      if (privmode == 0 && read_but_dont_execute == 0 && STREQN ("() {", string, 4))
+      if (import_functions && privmode == 0 && read_but_dont_execute == 0 && STREQN ("() {", string, 4))
 	{
 	  string_length = strlen (string);
 	  temp_string = (char *)xmalloc (3 + string_length + char_index);
