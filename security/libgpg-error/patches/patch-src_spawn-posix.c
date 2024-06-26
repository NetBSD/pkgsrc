$NetBSD: patch-src_spawn-posix.c,v 1.1 2024/06/26 19:31:56 adam Exp $

environ must be declared.

--- src/spawn-posix.c.orig	2024-06-19 07:33:41.000000000 +0000
+++ src/spawn-posix.c
@@ -53,6 +53,8 @@
 #if __linux__
 # include <sys/types.h>
 # include <dirent.h>
+#else
+extern char **environ;
 #endif /*__linux__ */
 
 #include "gpgrt-int.h"
