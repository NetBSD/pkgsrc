$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.2 2019/01/20 09:50:28 tnn Exp $

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2019-01-17 11:26:22.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -725,7 +725,11 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
       }
       dri2_dpy->own_device = true;
    } else {
+#ifdef F_DUPFD_CLOEXEC
       dri2_dpy->fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#else
+      dri2_dpy->fd = -1;
+#endif
       if (dri2_dpy->fd < 0) {
          err = "DRI2: failed to fcntl() existing gbm device";
          goto cleanup;
