$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.12 2026/11/03 16:53:44 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2026-10-22 10:57:01.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -23,6 +23,8 @@ pdfium_patches += system-dragonbox.diff
 pdfium_patches += system-fast_float.diff
 pdfium_patches += system-dragonbox.diff
 
+pdfium_patches += pkgsrc.patch.1
+
 ifeq ($(OS),WNT)
 pdfium_patches += pdfium-vs2019-arm64_no-__umulh.patch.1
 endif
