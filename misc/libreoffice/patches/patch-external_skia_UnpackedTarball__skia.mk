$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.13 2024/08/24 02:57:35 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2024-08-22 12:19:08.702670422 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -43,6 +43,7 @@ skia_patches := \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
     sort-comparison-assumption.patch.0 \
     help-msvc-analyzer.patch \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
