$NetBSD: patch-vmhgfs-fuse_fsutil.h,v 1.1 2016/11/21 00:14:16 pho Exp $

loff_t needs to be typedef'ed on NetBSD too.

--- vmhgfs-fuse/fsutil.h.orig	2016-02-16 20:06:49.000000000 +0000
+++ vmhgfs-fuse/fsutil.h
@@ -32,7 +32,7 @@
 #include "hgfsProto.h"
 #include <fuse.h>
 
-#if defined(__FreeBSD__) || defined(__SOLARIS__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__SOLARIS__) || defined(__APPLE__) || defined(__NetBSD__)
 typedef long long loff_t;
 #endif
 
