$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.2 2020/11/01 12:17:29 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2020-10-21 20:09:11.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,7 @@ skia_patches := \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     public-make-from-backend-texture.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
