$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.17 2026/06/06 15:04:31 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2026-03-19 21:35:00.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -23,7 +23,6 @@ skia_patches := \
     windows-do-not-modify-logfont.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -45,6 +44,7 @@ skia_patches := \
     msvc-unknown-attributes.patch.1 \
 	fix-semaphore-include.patch.1 \
 	fix-xputimage-depth.patch.1 \
+    netbsd.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
