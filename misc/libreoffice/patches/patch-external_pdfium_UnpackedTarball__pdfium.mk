$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.8 2024/07/25 06:09:45 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2024-07-11 15:10:12.112490280 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -18,6 +18,8 @@ pdfium_patches += constexpr-template.pat
 
 pdfium_patches += annot.patch.1
 
+pdfium_patches += pkgsrc.patch.1
+
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
 $(eval $(call gb_UnpackedTarball_set_tarball,pdfium,$(PDFIUM_TARBALL)))
