$NetBSD: patch-source_blender_blenlib_intern_storage.c,v 1.1 2022/05/23 05:21:25 dholland Exp $

Use statvfs on Solaris. (From PR 35928)

--- source/blender/blenlib/intern/storage.c~	2021-08-10 01:31:50.000000000 +0000
+++ source/blender/blenlib/intern/storage.c
@@ -29,7 +29,7 @@
 
 #include <sys/stat.h>
 
-#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__HAIKU__)
+#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__sun)
 /* Other modern unix OS's should probably use this also. */
 #  include <sys/statvfs.h>
 #  define USE_STATFS_STATVFS
