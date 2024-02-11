$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.12 2024/02/11 15:31:58 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2024-01-31 14:38:39.083441799 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     ubsan-missing-typeinfo.patch.1 \
     incomplete-type-SkImageGenerator.patch.1 \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
