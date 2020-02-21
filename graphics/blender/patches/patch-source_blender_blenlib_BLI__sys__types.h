$NetBSD: patch-source_blender_blenlib_BLI__sys__types.h,v 1.1 2020/02/21 16:36:54 nia Exp $

NetBSD also does not have uchar.h.

--- source/blender/blenlib/BLI_sys_types.h.orig	2020-02-21 13:50:55.328090564 +0000
+++ source/blender/blenlib/BLI_sys_types.h
@@ -73,7 +73,7 @@ typedef uint64_t u_int64_t;
 #include <stdbool.h>
 
 #ifndef __cplusplus
-#  if defined(__APPLE__)
+#  if defined(__APPLE__) || defined(__NetBSD__)
 /* The <uchar.h> standard header is missing on macOS. */
 typedef unsigned int char32_t;
 #  else
