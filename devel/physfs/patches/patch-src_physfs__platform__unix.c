$NetBSD: patch-src_physfs__platform__unix.c,v 1.1 2017/11/28 14:47:31 wiz Exp $

NetBSD support.

--- src/physfs_platform_unix.c.orig	2017-10-26 18:38:03.000000000 +0000
+++ src/physfs_platform_unix.c
@@ -56,6 +56,10 @@
 #ifdef PHYSFS_PLATFORM_FREEBSD
 #include <sys/sysctl.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 
 #include "physfs_internal.h"
