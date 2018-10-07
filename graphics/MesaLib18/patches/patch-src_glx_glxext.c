$NetBSD: patch-src_glx_glxext.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Patch from FreeBSD ports graphics/mesa-dri 18.0.0

# work-around for https://bugs.freedesktop.org/show_bug.cgi?id=100627

* Extended to DragonFly and NetBSD.  Other OSes might need this as well.

* Added logging statements to note dri3 initialization being invoked.

--- src/glx/glxext.c.orig	2017-12-08 13:49:11.000000000 +0000
+++ src/glx/glxext.c
@@ -55,6 +55,7 @@
 #include <xcb/xcb.h>
 #include <xcb/glx.h>
 
+#include "dri_common.h"
 
 #ifdef DEBUG
 void __glXDumpDrawBuffer(struct glx_context * ctx);
@@ -817,7 +818,11 @@ AllocAndFetchScreenConfigs(Display * dpy
 #if defined(GLX_USE_DRM)
 #if defined(HAVE_DRI3)
       if (priv->dri3Display)
+         InfoMessageF("glxext.c: AllocAndFetchScreenConfigs: priv->dri3Display\n");
+      if (priv->dri3Display)
          psc = (*priv->dri3Display->createScreen) (i, priv);
+      if (psc != NULL && priv->dri3Display)
+         InfoMessageF("glxext.c: AllocAndFetchScreenConfigs: psc set by priv->dri3Display\n");
 #endif /* HAVE_DRI3 */
       if (psc == NULL && priv->dri2Display)
 	 psc = (*priv->dri2Display->createScreen) (i, priv);
@@ -920,8 +925,13 @@ __glXInitialize(Display * dpy)
 #if defined(GLX_USE_DRM)
    if (glx_direct && glx_accel) {
 #if defined(HAVE_DRI3)
-      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false))
+#if ((defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined(__DRM_NEXT__)) || defined(__DragonFly__) || defined(__NetBSD__)
+      if (env_var_as_boolean("LIBGL_DRI3_ENABLE", false))
+#endif
+      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false)) {
+         InfoMessageF("glxext.c: __glxInitialize: dpyPriv->dri3Display = dri3_create_display\n");
          dpyPriv->dri3Display = dri3_create_display(dpy);
+      }
 #endif /* HAVE_DRI3 */
       dpyPriv->dri2Display = dri2CreateDisplay(dpy);
       dpyPriv->driDisplay = driCreateDisplay(dpy);
