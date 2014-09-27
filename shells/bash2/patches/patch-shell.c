$NetBSD: patch-shell.c,v 1.1 2014/09/27 03:00:06 christos Exp $

Add flag to disable importing of function unless explicitly enabled

--- shell.c.orig	2002-07-01 11:27:11.000000000 -0400
+++ shell.c	2014-09-26 22:52:27.000000000 -0400
@@ -197,6 +197,7 @@
 int dump_translatable_strings;	/* Dump strings in $"...", don't execute. */
 int dump_po_strings;		/* Dump strings in $"..." in po format */
 int wordexp_only = 0;		/* Do word expansion only */
+int import_functions = 0;	/* Import functions from environment */
 
 /* Some long-winded argument names.  These are obviously new. */
 #define Int 1
@@ -213,6 +214,7 @@
   { "help", Int, &want_initial_help, (char **)0x0 },
   { "init-file", Charp, (int *)0x0, &bashrc_file },
   { "login", Int, &make_login_shell, (char **)0x0 },
+  { "import-functions", Int, &import_functions, (char **)0x0 },
   { "noediting", Int, &no_line_editing, (char **)0x0 },
   { "noprofile", Int, &no_profile, (char **)0x0 },
   { "norc", Int, &no_rc, (char **)0x0 },
