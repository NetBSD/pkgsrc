$NetBSD: patch-src_df.c,v 1.1 2014/02/17 11:21:55 fhajny Exp $

NetBSD doesn't have float_t.
--- src/df.c.orig	2014-01-26 08:09:14.856391886 +0000
+++ src/df.c
@@ -28,6 +28,10 @@
 #include "utils_mount.h"
 #include "utils_ignorelist.h"
 
+#if defined(__NetBSD__)
+typedef float float_t;
+#endif
+
 #if HAVE_STATVFS
 # if HAVE_SYS_STATVFS_H
 #  include <sys/statvfs.h>
