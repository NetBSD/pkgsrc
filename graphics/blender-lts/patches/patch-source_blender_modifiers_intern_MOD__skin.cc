$NetBSD: patch-source_blender_modifiers_intern_MOD__skin.cc,v 1.1 2024/07/25 06:00:39 ryoon Exp $

--- source/blender/modifiers/intern/MOD_skin.cc.orig	2024-07-02 09:54:20.973834863 +0000
+++ source/blender/modifiers/intern/MOD_skin.cc
@@ -977,7 +977,7 @@ static Mesh *subdivide_base(const Mesh *
 
     u = edge[0];
     radrat = (half_v2(outnode[edge[1]].radius) / half_v2(outnode[edge[0]].radius));
-    if (isfinite(radrat)) {
+    if (std::isfinite(radrat)) {
       radrat = (radrat + 1) / 2;
     }
     else {
