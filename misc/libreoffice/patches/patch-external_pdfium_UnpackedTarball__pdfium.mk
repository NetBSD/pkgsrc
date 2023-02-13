$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.7 2023/02/13 14:59:36 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2023-01-25 14:26:33.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -25,6 +25,8 @@ pdfium_patches += abseil-trivial.patch
 
 pdfium_patches += constexpr-template.patch
 
+pdfium_patches += pkgsrc.patch.1
+
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
 $(eval $(call gb_UnpackedTarball_set_tarball,pdfium,$(PDFIUM_TARBALL)))
