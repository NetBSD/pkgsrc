$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.2 2026/11/25 13:47:16 wiz Exp $

Revert: https://cgit.freedesktop.org/mesa/mesa/commit/?id=621b0fa8922ade0a8122b868177308e65e6d3595

This causes symbol referencing errors:
"ld: /usr/pkg/lib/libEGL.so.1: undefined reference to `gbm_format_get_name'"

TODO: Talk to upstream and investigate why.

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
