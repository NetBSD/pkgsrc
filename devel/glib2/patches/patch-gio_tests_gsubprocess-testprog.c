$NetBSD: patch-gio_tests_gsubprocess-testprog.c,v 1.1 2023/11/03 18:32:32 otis Exp $

Include sys/ptrace.h only on systems that have this include file.

--- gio/tests/gsubprocess-testprog.c.orig	2023-09-08 13:42:18.000000000 +0000
+++ gio/tests/gsubprocess-testprog.c
@@ -5,7 +5,9 @@
 #include <errno.h>
 #ifdef G_OS_UNIX
 #include <unistd.h>
+#ifdef HAVE_SYS_PTRACE_H
 #include <sys/ptrace.h>
+#endif
 #else
 #include <io.h>
 #endif
