$NetBSD: patch-source_blender_blenkernel_intern_multires.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/blenkernel/intern/multires.cc.orig	2022-11-04 00:33:06.000000000 +0000
+++ source/blender/blenkernel/intern/multires.cc
@@ -1290,7 +1290,7 @@ void old_mdisps_bilinear(float out[3], f
   float urat, vrat, uopp;
   float d[4][3], d2[2][3];
 
-  if (!disps || isnan(u) || isnan(v)) {
+  if (!disps || std::isnan(u) || std::isnan(v)) {
     return;
   }
 
