$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.9 2023/03/10 20:57:38 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2023-02-22 19:52:27.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
     tdf147342.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
