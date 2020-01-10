$NetBSD: patch-physfs_physfs__platform__unix.c,v 1.1 2020/01/10 18:27:18 nia Exp $

Support NetBSD.

--- physfs/physfs_platform_unix.c.orig	2020-01-10 16:45:29.000000000 +0000
+++ physfs/physfs_platform_unix.c
@@ -57,6 +57,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include "physfs_internal.h"
 
