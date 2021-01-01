$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.4 2021/01/01 13:17:44 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2020-07-29 19:29:17.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -14,6 +14,8 @@ pdfium_patches += build.patch.1
 # Avoids Windows 8 build dependency.
 pdfium_patches += windows7.patch.1
 pdfium_patches += c++20-comparison.patch
+pdfium_patches += pkgsrc.patch.1
+
 
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
