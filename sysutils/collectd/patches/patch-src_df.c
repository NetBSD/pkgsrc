$NetBSD: patch-src_df.c,v 1.6 2020/10/24 22:39:45 wiz Exp $

Older NetBSD doesn't have float_t.

--- src/df.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/df.c	2020-07-06 19:28:15.661572605 +0200
@@ -28,6 +28,14 @@
 #include "utils/ignorelist/ignorelist.h"
 #include "utils/mount/mount.h"
 
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
