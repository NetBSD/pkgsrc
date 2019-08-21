$NetBSD: patch-src_glx_dri__common.h,v 1.1 2019/08/21 13:35:28 nia Exp $

Fix error on OSX.

--- src/glx/dri_common.h.orig	2019-01-17 11:26:23.000000000 +0000
+++ src/glx/dri_common.h
@@ -55,8 +55,10 @@ extern struct glx_config *driConvertConf
 
 extern void driDestroyConfigs(const __DRIconfig **configs);
 
+#if !defined(GLX_USE_APPLEGL)
 extern __GLXDRIdrawable *
 driFetchDrawable(struct glx_context *gc, GLXDrawable glxDrawable);
+#endif
 
 extern void
 driReleaseDrawables(struct glx_context *gc);
