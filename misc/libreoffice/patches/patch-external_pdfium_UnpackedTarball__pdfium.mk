$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.2 2020/02/07 03:52:28 tnn Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2020-01-22 23:14:16.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -14,6 +14,8 @@ pdfium_patches += ubsan.patch
 pdfium_patches += build.patch.1
 # Avoids Windows 8 build dependency.
 pdfium_patches += windows7.patch.1
+pdfium_patches += pkgsrc.patch.1
+pdfium_patches += pkgsrc2.patch.1
 
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
