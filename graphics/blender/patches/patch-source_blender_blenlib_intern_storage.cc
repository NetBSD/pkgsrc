$NetBSD: patch-source_blender_blenlib_intern_storage.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

Use statvfs on Solaris. (From PR 35928)

--- source/blender/blenlib/intern/storage.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/blenlib/intern/storage.cc
@@ -14,7 +14,7 @@
 
 #include <sys/stat.h>
 
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__sun)
 /* Other modern unix OS's should probably use this also. */
 #  include <sys/statvfs.h>
 #  define USE_STATFS_STATVFS
