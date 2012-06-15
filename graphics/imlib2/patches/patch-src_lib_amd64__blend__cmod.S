$NetBSD: patch-src_lib_amd64__blend__cmod.S,v 1.1 2012/06/15 18:52:26 joerg Exp $

--- src/lib/amd64_blend_cmod.S.orig	2012-06-15 15:25:46.000000000 +0000
+++ src/lib/amd64_blend_cmod.S
@@ -86,8 +86,6 @@ FN_(imlib_amd64_reshade_copy_rgba_to_rgb
 FN_(imlib_amd64_reshade_copy_rgba_to_rgba_cmod)
 FN_(imlib_amd64_reshade_copy_rgb_to_rgba_cmod)
 
-.extern pow_lut
-	
 /*\ SSE register use:
 |*| %xmm1 = Source value
 |*| %xmm2 = Destination value
