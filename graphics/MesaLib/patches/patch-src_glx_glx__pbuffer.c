$NetBSD: patch-src_glx_glx__pbuffer.c,v 1.1 2023/07/14 06:27:52 pho Exp $

GLX_EXT_swap_control doesn't work on systems running on vmwgfx. I don't
think this is a proper fix, and the upstream bug report has been seemingly
stuck, but is still necessary for VMware guests. glxgear(1) from
graphics/glx-utils crashes on startup without this workaround.

https://gitlab.freedesktop.org/mesa/mesa/-/issues/4495

--- src/glx/glx_pbuffer.c.orig	2023-07-12 04:37:57.945531844 +0000
+++ src/glx/glx_pbuffer.c
@@ -309,7 +309,8 @@ __glXGetDrawableAttribute(Display * dpy,
    }
 
    if (pdraw) {
-      if (attribute == GLX_SWAP_INTERVAL_EXT) {
+      if (attribute == GLX_SWAP_INTERVAL_EXT
+          && pdraw->psc->driScreen->getSwapInterval != NULL) {
          *value = pdraw->psc->driScreen->getSwapInterval(pdraw);
          return 0;
       } else if (attribute == GLX_MAX_SWAP_INTERVAL_EXT) {
