$NetBSD: patch-src_command.c,v 1.3 2017/11/03 15:00:10 adam Exp $

Fix for some platforms where WEXITSTATUS gets undefined.

--- src/command.c.orig	2017-11-03 14:50:58.000000000 +0000
+++ src/command.c
@@ -3640,6 +3640,9 @@ do_system_func(const char *cmd, char **o
 #if defined(_WIN32) && !defined(WEXITSTATUS)
 #define WEXITSTATUS(error) (error)
 #endif
+#if !defined(WEXITSTATUS)
+#include <sys/wait.h>
+#endif
 
 static int
 report_error(int ierr)
