$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.18 2026/09/22 08:34:00 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2026-08-21 12:51:44.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -22,7 +22,6 @@ skia_patches := \
     windows-do-not-modify-logfont.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     swap-buffers-rect.patch.1 \
     ubsan.patch.1 \
@@ -43,6 +42,7 @@ skia_patches := \
     msvc-unknown-attributes.patch.1 \
 	fix-semaphore-include.patch.1 \
 	fix-xputimage-depth.patch.1 \
+    netbsd.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
