$NetBSD: patch-source_blender_blenloader_intern_readfile.h,v 1.1 2019/09/18 23:40:17 nia Exp $

NetBSD does not have off64_t.

--- source/blender/blenloader/intern/readfile.h.orig	2019-07-24 07:41:39.000000000 +0000
+++ source/blender/blenloader/intern/readfile.h
@@ -53,7 +53,7 @@ enum eFileDataFlag {
 #  pragma GCC poison off_t
 #endif
 
-#if defined(_MSC_VER) || defined(__APPLE__) || defined(__HAIKU__)
+#if defined(_MSC_VER) || defined(__APPLE__) || defined(__HAIKU__) || defined(__NetBSD__)
 typedef int64_t off64_t;
 #endif
 
