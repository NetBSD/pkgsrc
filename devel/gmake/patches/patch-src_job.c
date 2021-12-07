$NetBSD: patch-src_job.c,v 1.1 2021/12/07 12:06:16 jperkin Exp $

If we bootstrap pkgsrc with a different shell, use it.

Add our bootstrap shells to the POSIX-compatible list, required for correct
operation of .ONESHELL mode.

--- src/job.c.orig	2020-01-19 20:32:59.000000000 +0000
+++ src/job.c
@@ -77,7 +77,11 @@ char * vms_strsignal (int status);
 
 #else
 
+#ifdef PKGSRC_DEFAULT_SHELL
+const char *default_shell = PKGSRC_DEFAULT_SHELL;
+#else
 const char *default_shell = "/bin/sh";
+#endif
 int batch_mode_shell = 0;
 
 #endif
@@ -433,6 +437,8 @@ is_bourne_compatible_shell (const char *
     "zsh",
     "ash",
     "dash",
+    "mksh",
+    "pdksh",
     NULL
   };
   const char **s;
