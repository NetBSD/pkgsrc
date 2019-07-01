$NetBSD: patch-external_physfs_src_physfs__platform__unix.c,v 1.1 2019/07/01 15:13:20 nia Exp $

Support NetBSD.

--- external/physfs/src/physfs_platform_unix.c.orig	2018-12-23 19:11:38.000000000 +0000
+++ external/physfs/src/physfs_platform_unix.c
@@ -57,6 +57,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include "physfs_internal.h"
 
