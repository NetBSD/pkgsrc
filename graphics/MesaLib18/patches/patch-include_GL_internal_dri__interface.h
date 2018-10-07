$NetBSD: patch-include_GL_internal_dri__interface.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

From FreeBSD ports graphics/mesa-dri 17.2.4.

GCC on 9.x doesn't allow types to be overwritten, these types are defined
in drm.h also, which causes build issues in xorg-server.

--- include/GL/internal/dri_interface.h.orig	2017-11-20 14:25:47.000000000 +0000
+++ include/GL/internal/dri_interface.h
@@ -40,6 +40,9 @@
 #ifndef DRI_INTERFACE_H
 #define DRI_INTERFACE_H
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <drm.h>
+#else
 #ifdef HAVE_LIBDRM
 #include <drm.h>
 #else
@@ -47,6 +50,7 @@ typedef unsigned int drm_context_t;
 typedef unsigned int drm_drawable_t;
 typedef struct drm_clip_rect drm_clip_rect_t;
 #endif
+#endif /* __FreeBSD__ || __DragonFly__ */
 
 #include <stdint.h>
 
