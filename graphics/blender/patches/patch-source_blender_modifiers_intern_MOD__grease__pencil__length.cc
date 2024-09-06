$NetBSD: patch-source_blender_modifiers_intern_MOD__grease__pencil__length.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/modifiers/intern/MOD_grease_pencil_length.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/modifiers/intern/MOD_grease_pencil_length.cc
@@ -168,7 +168,7 @@ static void deform_drawing(const Modifie
 
           rand[j] = math::mod(float(r[j] + rand_offset), 1.0f);
           rand[j] = math::abs(
-              math::mod(sin(rand[j] * 12.9898f + j * 78.233f) * 43758.5453f, 1.0f) + noise);
+              math::mod(static_cast<float>(sin(rand[j] * 12.9898f + j * 78.233f) * 43758.5453f), 1.0f) + noise);
         }
 
         modified_starts[i] = modified_starts[i] + rand[0] * mmd.rand_start_fac;
