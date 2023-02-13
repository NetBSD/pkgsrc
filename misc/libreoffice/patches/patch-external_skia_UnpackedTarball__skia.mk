$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.8 2023/02/13 14:59:36 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2023-01-25 14:26:33.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -40,6 +40,7 @@ skia_patches := \
     tdf148624.patch.1 \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
