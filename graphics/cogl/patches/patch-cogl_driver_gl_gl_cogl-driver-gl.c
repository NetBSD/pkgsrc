$NetBSD: patch-cogl_driver_gl_gl_cogl-driver-gl.c,v 1.2 2015/01/17 14:28:51 prlw1 Exp $

* prepare missing OpenGL ARB_sync extension.
  https://bugzilla.gnome.org/show_bug.cgi?id=741646

--- cogl/driver/gl/gl/cogl-driver-gl.c.orig	2014-07-02 23:31:31.000000000 +0000
+++ cogl/driver/gl/gl/cogl-driver-gl.c
@@ -634,8 +634,10 @@ _cogl_driver_update_features (CoglContex
   COGL_FLAGS_SET (private_features,
                   COGL_PRIVATE_FEATURE_TEXTURE_MAX_LEVEL, TRUE);
 
+#ifdef GL_ARB_sync
   if (ctx->glFenceSync)
     COGL_FLAGS_SET (ctx->features, COGL_FEATURE_ID_FENCE, TRUE);
+#endif
 
   if (COGL_CHECK_GL_VERSION (gl_major, gl_minor, 3, 0) ||
       _cogl_check_extension ("GL_ARB_texture_rg", gl_extensions))
