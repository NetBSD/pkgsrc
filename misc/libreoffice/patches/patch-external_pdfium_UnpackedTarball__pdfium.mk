$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.9 2025/02/05 03:50:02 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2025-01-30 14:17:29.500653471 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -18,6 +18,8 @@ pdfium_patches += constexpr-template.pat
 
 pdfium_patches += system-abseil.diff
 
+pdfium_patches += pkgsrc.patch.1
+
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
 $(eval $(call gb_UnpackedTarball_set_tarball,pdfium,$(PDFIUM_TARBALL)))
