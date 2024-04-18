$NetBSD: patch-src_s3fs.h,v 1.1 2024/04/18 04:02:26 pho Exp $

Fix build with refuse(3): This is wrong. src/s3fs.cpp mentions struct
fuse_operations::flag_utime_omit_ok, which was introduced in FUSE 2.9.

TODO: Upstream this

--- src/s3fs.h.orig	2024-04-17 14:02:52.187432597 +0000
+++ src/s3fs.h
@@ -21,7 +21,7 @@
 #ifndef S3FS_S3FS_H_
 #define S3FS_S3FS_H_
 
-#define FUSE_USE_VERSION      26
+#define FUSE_USE_VERSION      29
 
 #include <fuse.h>
 
