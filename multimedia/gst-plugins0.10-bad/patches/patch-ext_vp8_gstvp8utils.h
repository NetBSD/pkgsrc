$NetBSD: patch-ext_vp8_gstvp8utils.h,v 1.1 2015/12/25 20:07:42 joerg Exp $

--- ext/vp8/gstvp8utils.h.orig	2015-12-25 18:17:38.000000000 +0000
+++ ext/vp8/gstvp8utils.h
@@ -26,10 +26,6 @@
 G_BEGIN_DECLS
 
 /* Some compatibility defines for older libvpx versions */
-#ifndef VPX_IMG_FMT_I420
-#define VPX_IMG_FMT_I420 IMG_FMT_I420
-#endif
-
 #ifndef VPX_PLANE_Y
 #define VPX_PLANE_Y PLANE_Y
 #endif
