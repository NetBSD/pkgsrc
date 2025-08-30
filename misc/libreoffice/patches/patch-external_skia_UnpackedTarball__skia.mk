$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.15 2025/08/30 06:44:05 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2025-08-12 11:36:36.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -23,7 +23,6 @@ skia_patches := \
     windows-do-not-modify-logfont.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -42,6 +41,7 @@ skia_patches := \
 	0002-loong64-Honor-existing-LASX-LSX-settings.patch \
 	0003-loong64-Fix-missing-rounding-in-loong64-scaled_mult-.patch \
 	0004-loong64-Fix-the-remaining-implicit-vector-casts.patch \
+    netbsd.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
