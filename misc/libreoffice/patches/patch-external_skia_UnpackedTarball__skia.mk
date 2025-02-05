$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.14 2025/02/05 03:50:02 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2025-01-23 21:25:49.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -24,7 +24,6 @@ skia_patches := \
     windows-text-gamma.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -41,6 +40,7 @@ skia_patches := \
     help-msvc-analyzer.patch \
     always_inline_and_multiversioning_conflict.patch.1 \
     windows-define-conflict.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
