$NetBSD: patch-src_df.c,v 1.5 2016/12/07 17:28:39 fhajny Exp $

Older NetBSD doesn't have float_t.

--- src/df.c.orig	2016-11-30 08:52:01.312911569 +0000
+++ src/df.c
@@ -28,6 +28,14 @@
 #include "utils_ignorelist.h"
 #include "utils_mount.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <math.h>
+#if __NetBSD_Version__ < 699001900
+typedef float float_t;
+#endif
+#endif
+
 #if HAVE_STATVFS
 #if HAVE_SYS_STATVFS_H
 #include <sys/statvfs.h>
