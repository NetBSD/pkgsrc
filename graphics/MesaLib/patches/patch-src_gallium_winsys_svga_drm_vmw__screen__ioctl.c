$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen__ioctl.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Make sure ERESTART gets defined.

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2015-03-21 00:51:18.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -48,6 +48,13 @@
 
 #include "os/os_mman.h"
 
+#if defined(__NetBSD__)
+#define _KMEMUSER
+#include <errno.h>
+#if !defined(ERESTART)
+#define ERESTART -3
+#endif
+#endif
 #include <errno.h>
 #include <unistd.h>
 
