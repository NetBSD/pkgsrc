$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.1 2026/11/23 10:29:52 adam Exp $

--- src/egl/drivers/dri2/platform_drm.c.orig	2025-05-02 17:22:18.878824432 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -523,9 +523,8 @@ drm_add_configs_for_visuals(_EGLDisplay 
 
    for (unsigned i = 0; i < ARRAY_SIZE(format_count); i++) {
       if (!format_count[i]) {
-         struct gbm_format_name_desc desc;
-         _eglLog(_EGL_DEBUG, "No DRI config supports native format %s",
-                 gbm_format_get_name(visuals[i].gbm_format, &desc));
+         _eglLog(_EGL_DEBUG, "No DRI config supports native format 0x%x",
+                 visuals[i].gbm_format);
       }
    }
 }
