$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.1 2020/08/11 16:07:39 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2020-07-29 19:29:17.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,7 @@ skia_patches := \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     c++20.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
