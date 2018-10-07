$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2017-10-19 12:23:53.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -688,7 +688,9 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
       }
       dri2_dpy->own_device = true;
    } else {
+#ifdef F_DUPFD_CLOEXEC
       dri2_dpy->fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#endif
       if (dri2_dpy->fd < 0) {
          err = "DRI2: failed to fcntl() existing gbm device";
          goto cleanup;
