$NetBSD: patch-src_egl_drivers_dri2_platform__drm.c,v 1.5 2020/01/21 14:41:26 nia Exp $

Revert: https://cgit.freedesktop.org/mesa/mesa/commit/?id=621b0fa8922ade0a8122b868177308e65e6d3595

This causes symbol referencing errors:
"ld: /usr/pkg/lib/libEGL.so.1: undefined reference to `gbm_format_get_name'"

TODO: Talk to upstream and investigate why.

--- src/egl/drivers/dri2/platform_drm.c.orig	2019-12-04 22:10:12.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -649,9 +649,8 @@ drm_add_configs_for_visuals(_EGLDriver *
 
    for (unsigned i = 0; i < ARRAY_SIZE(format_count); i++) {
       if (!format_count[i]) {
-         struct gbm_format_name_desc desc;
-         _eglLog(_EGL_DEBUG, "No DRI config supports native format %s",
-                 gbm_format_get_name(visuals[i].gbm_format, &desc));
+         _eglLog(_EGL_DEBUG, "No DRI config supports native format 0x%x",
+                 visuals[i].gbm_format);
       }
    }
 
