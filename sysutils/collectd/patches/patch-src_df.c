$NetBSD: patch-src_df.c,v 1.2 2015/08/16 08:39:02 he Exp $

NetBSD doesn't have float_t.

--- src/df.c.orig	2014-01-26 08:09:14.856391886 +0000
+++ src/df.c
@@ -28,6 +28,10 @@
 #include "utils_mount.h"
 #include "utils_ignorelist.h"
 
+#if defined(__NetBSD__)
+#include <math.h>
+#endif
+
 #if HAVE_STATVFS
 # if HAVE_SYS_STATVFS_H
 #  include <sys/statvfs.h>
