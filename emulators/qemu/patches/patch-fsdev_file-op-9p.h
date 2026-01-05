$NetBSD: patch-fsdev_file-op-9p.h,v 1.2 2026/01/05 10:11:37 adam Exp $

Add BSD support for fsdev 9p.

--- fsdev/file-op-9p.h.orig	2025-12-23 19:48:56.000000000 +0000
+++ fsdev/file-op-9p.h
@@ -28,6 +28,11 @@
 # endif
 # include <sys/mount.h>
 #endif
+#ifdef __NetBSD__
+# include <sys/statvfs.h>
+# define statfs statvfs
+# define fstatfs fstatvfs
+#endif
 
 #define SM_LOCAL_MODE_BITS    0600
 #define SM_LOCAL_DIR_MODE_BITS    0700
