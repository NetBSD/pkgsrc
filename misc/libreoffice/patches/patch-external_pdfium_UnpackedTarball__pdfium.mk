$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.11 2026/02/09 16:59:59 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2026-01-27 21:11:38.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -22,6 +22,8 @@ pdfium_patches += system-fast_float.diff
 
 pdfium_patches += system-fast_float.diff
 
+pdfium_patches += pkgsrc.patch.1
+
 ifeq ($(OS),WNT)
 pdfium_patches += pdfium-vs2019-arm64_no-__umulh.patch.1
 endif
