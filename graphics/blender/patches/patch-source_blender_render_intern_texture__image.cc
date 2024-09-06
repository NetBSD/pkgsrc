$NetBSD: patch-source_blender_render_intern_texture__image.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/render/intern/texture_image.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/render/intern/texture_image.cc
@@ -1261,7 +1261,7 @@ static int imagewraposa_aniso(Tex *tex,
       }
     }
     else {
-      const int lev = isnan(levf) ? 0 : int(levf);
+      const int lev = std::isnan(levf) ? 0 : int(levf);
       curibuf = mipmaps[lev];
       previbuf = mipmaps[lev + 1];
       levf -= floorf(levf);
