$NetBSD: patch-src_job.c,v 1.2 2022/11/17 23:51:33 wiz Exp $

If we bootstrap pkgsrc with a different shell, use it.

Add our bootstrap shells to the POSIX-compatible list, required for correct
operation of .ONESHELL mode.

--- src/job.c.orig	2022-10-31 06:23:04.000000000 +0000
+++ src/job.c
@@ -79,7 +79,11 @@ char * vms_strsignal (int status);
 
 #else
 
+#ifdef PKGSRC_DEFAULT_SHELL
+const char *default_shell = PKGSRC_DEFAULT_SHELL;
+#else
 const char *default_shell = "/bin/sh";
+#endif
 int batch_mode_shell = 0;
 
 #endif
@@ -441,6 +445,8 @@ is_bourne_compatible_shell (const char *
     "bash",
     "dash",
     "ksh",
+    "mksh",
+    "pdksh",
     "rksh",
     "zsh",
     "ash",
