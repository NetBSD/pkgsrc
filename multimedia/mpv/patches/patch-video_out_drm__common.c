$NetBSD: patch-video_out_drm__common.c,v 1.5 2024/10/20 09:28:29 leot Exp $

Enable support for DRM on NetBSD.

--- video/out/drm_common.c.orig	2024-09-23 17:36:41.000000000 +0000
+++ video/out/drm_common.c
@@ -34,6 +34,7 @@
 #elif HAVE_VT_H
 #include <sys/vt.h>
 #elif HAVE_WSDISPLAY_USL_IO_H
+#include <sys/types.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif
 
