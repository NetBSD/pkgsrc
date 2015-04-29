$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen__ioctl.c,v 1.2 2015/04/29 14:12:54 sevan Exp $

Make sure ERESTART gets defined.

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2015-03-21 00:51:18.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -48,6 +48,21 @@
 
 #include "os/os_mman.h"
 
+#if defined(__NetBSD__)
+#define _KMEMUSER
+#include <errno.h>
+#if !defined(ERESTART)
+#define ERESTART -3
+#endif
+#endif
+
+#if defined(__FreeBSD__)
+#include <errno.h>
+#if !defined(ERESTART)
+#define ERESTART -1
+#endif
+#endif
+
 #include <errno.h>
 #include <unistd.h>
 
