$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.16 2026/02/09 16:59:59 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2026-01-27 21:11:38.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -23,7 +23,6 @@ skia_patches := \
     windows-do-not-modify-logfont.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -44,6 +43,7 @@ skia_patches := \
 	0004-loong64-Fix-the-remaining-implicit-vector-casts.patch \
     msvc-unknown-attributes.patch.1 \
 	fix-semaphore-include.patch.1 \
+    netbsd.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
