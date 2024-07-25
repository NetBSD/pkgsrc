$NetBSD: patch-source_blender_modifiers_intern_MOD__ocean.cc,v 1.1 2024/07/25 06:00:39 ryoon Exp $

--- source/blender/modifiers/intern/MOD_ocean.cc.orig	2024-07-02 09:52:40.852208501 +0000
+++ source/blender/modifiers/intern/MOD_ocean.cc
@@ -319,7 +319,7 @@ static Mesh *doOcean(ModifierData *md, c
   const float size_co_inv = 1.0f / (omd->size * omd->spatial_size);
 
   /* can happen in when size is small, avoid bad array lookups later and quit now */
-  if (!isfinite(size_co_inv)) {
+  if (!std::isfinite(size_co_inv)) {
     return mesh;
   }
 
