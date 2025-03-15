$NetBSD: patch-fsdev_file-op-9p.h,v 1.1 2025/03/15 20:19:15 riastradh Exp $

Add BSD support for fsdev 9p.

--- fsdev/file-op-9p.h.orig	2024-12-10 23:46:36.000000000 +0000
+++ fsdev/file-op-9p.h
@@ -26,6 +26,11 @@
 # include <sys/param.h>
 # include <sys/mount.h>
 #endif
+#ifdef __NetBSD__
+# include <sys/statvfs.h>
+# define statfs statvfs
+# define fstatfs fstatvfs
+#endif
 
 #define SM_LOCAL_MODE_BITS    0600
 #define SM_LOCAL_DIR_MODE_BITS    0700
