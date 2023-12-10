$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.11 2023/12/10 11:51:21 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2023-11-30 13:04:41.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -40,6 +40,7 @@ skia_patches := \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
