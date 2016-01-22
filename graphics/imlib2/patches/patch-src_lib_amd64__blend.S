$NetBSD: patch-src_lib_amd64__blend.S,v 1.2 2016/01/22 21:07:00 leot Exp $

Drop .extern, it is ignored by GNU as and not supported by LLVM.

--- src/lib/amd64_blend.S.orig	2012-06-15 15:25:04.000000000 +0000
+++ src/lib/amd64_blend.S
@@ -78,8 +78,6 @@ FN_(imlib_amd64_reshade_copy_rgba_to_rgb
 FN_(imlib_amd64_reshade_copy_rgba_to_rgba)
 FN_(imlib_amd64_reshade_copy_rgb_to_rgba)
 
-.extern pow_lut
-	
 /*\ SSE register use:
 |*| %xmm1 = Source value
 |*| %xmm2 = Destination value
