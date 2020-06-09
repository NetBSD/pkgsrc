$NetBSD: patch-source_blender_blenlib_BLI__sys__types.h,v 1.2 2020/06/09 10:34:26 ryoon Exp $

NetBSD also does not have uchar.h.

--- source/blender/blenlib/BLI_sys_types.h.orig	2020-06-03 14:18:27.000000000 +0000
+++ source/blender/blenlib/BLI_sys_types.h
@@ -73,7 +73,7 @@ typedef uint64_t u_int64_t;
 #include <stddef.h> /* size_t define */
 
 #ifndef __cplusplus
-#  if defined(__APPLE__)
+#  if defined(__APPLE__) || defined(__NetBSD__)
 /* The <uchar.h> standard header is missing on macOS. */
 typedef unsigned int char32_t;
 #  else
