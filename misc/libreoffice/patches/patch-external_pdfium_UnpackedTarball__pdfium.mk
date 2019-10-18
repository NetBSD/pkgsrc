$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.1 2019/10/18 10:13:40 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2019-09-18 14:12:06.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -14,6 +14,7 @@ pdfium_patches += ubsan.patch
 pdfium_patches += build.patch.1
 # Avoids Windows 8 build dependency.
 pdfium_patches += windows7.patch.1
+pdfium_patches += pkgsrc.patch.1
 
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
