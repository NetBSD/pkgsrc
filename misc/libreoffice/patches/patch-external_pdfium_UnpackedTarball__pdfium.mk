$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.5 2021/02/06 06:47:24 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2021-01-27 19:33:49.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -18,6 +18,7 @@ pdfium_patches += AnnotationInkAndVertic
 pdfium_patches += AnnotationBorderProperties.patch.1
 pdfium_patches += AnnotationLineStartAndEnd.patch.1
 pdfium_patches += SignatureGetDocMDPPermission.patch.1
+pdfium_patches += pkgsrc.patch.1
 
 # Work around <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94141> "c++20 rewritten operator==
 # recursive call mixing friend and external operators for template class" in GCC with
