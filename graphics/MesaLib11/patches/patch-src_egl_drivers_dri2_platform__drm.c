$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.1 2019/08/21 13:35:29 nia Exp $

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2015-12-09 16:10:13.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -626,7 +626,9 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
       if (gbm == NULL)
          goto cleanup;
    } else {
+#ifdef F_DUPFD_CLOEXEC
       fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#endif
       if (fd < 0)
          goto cleanup;
    }
