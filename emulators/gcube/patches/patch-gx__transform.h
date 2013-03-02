$NetBSD: patch-gx__transform.h,v 1.1 2013/03/02 18:13:14 joerg Exp $

--- gx_transform.h.orig	2013-03-01 16:11:32.000000000 +0000
+++ gx_transform.h
@@ -2,17 +2,16 @@
 #define __GX_TRANSFORM_H 1
 
 
-
-inline __u32 color_unpack_rgb565 (__u32 X);
-inline __u32 color_unpack_rgba4 (__u32 X);
-inline __u32 color_unpack_rgba6 (__u32 X);
-inline __u32 color_unpack_rgb555 (__u32 X);
-inline __u32 color_unpack_rgb4a3 (__u32 X);
-inline __u32 color_unpack_rgb5a3 (__u32 X);
-inline __u32 color_unpack_i4 (__u32 X);
-inline __u32 color_unpack_i8 (__u32 X);
-inline __u32 color_unpack_ia4 (__u32 X);
-inline __u32 color_unpack_ia8 (__u32 X);
+__u32 color_unpack_rgb565 (__u32 X);
+__u32 color_unpack_rgba4 (__u32 X);
+__u32 color_unpack_rgba6 (__u32 X);
+__u32 color_unpack_rgb555 (__u32 X);
+__u32 color_unpack_rgb4a3 (__u32 X);
+__u32 color_unpack_rgb5a3 (__u32 X);
+__u32 color_unpack_i4 (__u32 X);
+__u32 color_unpack_i8 (__u32 X);
+__u32 color_unpack_ia4 (__u32 X);
+__u32 color_unpack_ia8 (__u32 X);
 
 unsigned int gx_draw (__u32 mem, int prim, int n, int vat);
 
