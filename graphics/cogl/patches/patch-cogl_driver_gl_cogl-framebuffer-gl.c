$NetBSD: patch-cogl_driver_gl_cogl-framebuffer-gl.c,v 1.1 2025/07/10 14:54:16 jperkin Exp $

Fix -Wint-conversion.

--- cogl/driver/gl/cogl-framebuffer-gl.c.orig	2025-07-10 14:45:03.397520735 +0000
+++ cogl/driver/gl/cogl-framebuffer-gl.c
@@ -810,7 +810,7 @@ _cogl_offscreen_gl_allocate (CoglOffscre
 
   _COGL_RETURN_VAL_IF_FAIL (offscreen->texture_level <
                             _cogl_texture_get_n_levels (offscreen->texture),
-                            NULL);
+                            FALSE);
 
   _cogl_texture_get_level_size (offscreen->texture,
                                 offscreen->texture_level,
