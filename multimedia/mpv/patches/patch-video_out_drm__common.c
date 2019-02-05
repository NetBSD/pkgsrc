$NetBSD: patch-video_out_drm__common.c,v 1.2 2019/02/05 12:07:57 leot Exp $

Enable support for DRM on NetBSD.

--- video/out/drm_common.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ video/out/drm_common.c
@@ -21,7 +21,12 @@
 #include <sys/ioctl.h>
 #include <poll.h>
 #include <sys/stat.h>
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <dev/wscons/wsdisplay_usl_io.h>
+#else
 #include <sys/vt.h>
+#endif
 #include <unistd.h>
 
 #include "drm_common.h"
