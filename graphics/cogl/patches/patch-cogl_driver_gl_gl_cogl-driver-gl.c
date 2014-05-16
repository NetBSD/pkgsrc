$NetBSD: patch-cogl_driver_gl_gl_cogl-driver-gl.c,v 1.1 2014/05/16 01:56:59 obache Exp $

* prepare missing OpenGL ARB_sync extension.

--- cogl/driver/gl/gl/cogl-driver-gl.c.orig	2014-01-20 17:31:02.000000000 +0000
+++ cogl/driver/gl/gl/cogl-driver-gl.c
@@ -616,8 +616,10 @@ _cogl_driver_update_features (CoglContex
                     COGL_PRIVATE_FEATURE_QUERY_TEXTURE_PARAMETERS |
                     COGL_PRIVATE_FEATURE_TEXTURE_MAX_LEVEL);
 
+#ifdef GL_ARB_sync
   if (ctx->glFenceSync)
     COGL_FLAGS_SET (ctx->features, COGL_FEATURE_ID_FENCE, TRUE);
+#endif
 
   /* Cache features */
   ctx->private_feature_flags |= private_flags;
