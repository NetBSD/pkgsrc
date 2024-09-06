$NetBSD: patch-source_blender_blenkernel_intern_particle__distribute.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/particle_distribute.cc.orig	2024-06-05 11:47:56.000000000 +0000
+++ source/blender/blenkernel/intern/particle_distribute.cc
@@ -543,7 +543,7 @@ static void distribute_from_faces_exec(P
       }
       else {
         float offset = fmod(ctx->jitoff[i] + float(p), float(ctx->jitlevel));
-        if (!isnan(offset)) {
+        if (!std::isnan(offset)) {
           psys_uv_to_w(
               ctx->jit[2 * int(offset)], ctx->jit[2 * int(offset) + 1], mface->v4, pa->fuv);
         }
@@ -596,7 +596,7 @@ static void distribute_from_volume_exec(
       }
       else {
         float offset = fmod(ctx->jitoff[i] + float(p), float(ctx->jitlevel));
-        if (!isnan(offset)) {
+        if (!std::isnan(offset)) {
           psys_uv_to_w(
               ctx->jit[2 * int(offset)], ctx->jit[2 * int(offset) + 1], mface->v4, pa->fuv);
         }
