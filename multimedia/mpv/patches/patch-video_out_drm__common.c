$NetBSD: patch-video_out_drm__common.c,v 1.4 2020/12/19 11:27:51 leot Exp $

Enable support for DRM on NetBSD.

--- video/out/drm_common.c.orig	2020-11-22 17:46:28.000000000 +0000
+++ video/out/drm_common.c
@@ -30,6 +30,9 @@
 
 #if HAVE_CONSIO_H
 #include <sys/consio.h>
+#elif HAVE_WSDISPLAY_USL_IO_H
+#include <sys/types.h>
+#include <dev/wscons/wsdisplay_usl_io.h>
 #else
 #include <sys/vt.h>
 #endif
