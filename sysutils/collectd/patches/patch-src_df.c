$NetBSD: patch-src_df.c,v 1.4 2015/08/18 07:52:20 he Exp $

Older NetBSD doesn't have float_t.

--- src/df.c.orig	2015-03-10 14:14:45.000000000 +0000
+++ src/df.c
@@ -28,6 +28,14 @@
 #include "utils_mount.h"
 #include "utils_ignorelist.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <math.h>
+#if __NetBSD_Version__ < 699001900
+typedef float float_t;
+#endif
+#endif
+
 #if HAVE_STATVFS
 # if HAVE_SYS_STATVFS_H
 #  include <sys/statvfs.h>
