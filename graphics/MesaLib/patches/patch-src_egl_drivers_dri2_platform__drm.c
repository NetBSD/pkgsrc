$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.1 2015/09/26 11:01:13 tnn Exp $

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2015-09-10 18:07:21.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -638,7 +638,9 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
    }
 
    if (fd < 0) {
+#ifdef F_DUPFD_CLOEXEC
       fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#endif
       if (fd < 0) {
          free(dri2_dpy);
          return EGL_FALSE;
