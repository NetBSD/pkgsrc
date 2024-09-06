$NetBSD: patch-source_blender_modifiers_intern_MOD__ocean.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/modifiers/intern/MOD_ocean.cc.orig	2024-06-28 12:50:36.000000000 +0000
+++ source/blender/modifiers/intern/MOD_ocean.cc
@@ -307,7 +307,7 @@ static Mesh *doOcean(ModifierData *md, c
   const float size_co_inv = 1.0f / (omd->size * omd->spatial_size);
 
   /* can happen in when size is small, avoid bad array lookups later and quit now */
-  if (!isfinite(size_co_inv)) {
+  if (!std::isfinite(size_co_inv)) {
     return mesh;
   }
 
