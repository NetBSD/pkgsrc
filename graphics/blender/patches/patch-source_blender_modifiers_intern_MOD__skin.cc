$NetBSD: patch-source_blender_modifiers_intern_MOD__skin.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/modifiers/intern/MOD_skin.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/modifiers/intern/MOD_skin.cc
@@ -973,7 +973,7 @@ static Mesh *subdivide_base(const Mesh *
 
     u = edge[0];
     radrat = (half_v2(outnode[edge[1]].radius) / half_v2(outnode[edge[0]].radius));
-    if (isfinite(radrat)) {
+    if (std::isfinite(radrat)) {
       radrat = (radrat + 1) / 2;
     }
     else {
