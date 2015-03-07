$NetBSD: patch-shell.c,v 1.2 2015/03/07 22:40:48 rodent Exp $

Add flag to disable importing of function unless explicitly enabled

--- shell.c.orig	2014-01-14 13:04:32.000000000 +0000
+++ shell.c
@@ -229,6 +229,7 @@ int posixly_correct = 1;	/* Non-zero mea
 #else
 int posixly_correct = 0;	/* Non-zero means posix.2 superset. */
 #endif
+int import_functions = 0;	/* Import functions from environment */
 
 /* Some long-winded argument names.  These are obviously new. */
 #define Int 1
@@ -248,6 +249,7 @@ static const struct {
   { "help", Int, &want_initial_help, (char **)0x0 },
   { "init-file", Charp, (int *)0x0, &bashrc_file },
   { "login", Int, &make_login_shell, (char **)0x0 },
+  { "import-functions", Int, &import_functions, (char **)0x0 },
   { "noediting", Int, &no_line_editing, (char **)0x0 },
   { "noprofile", Int, &no_profile, (char **)0x0 },
   { "norc", Int, &no_rc, (char **)0x0 },
