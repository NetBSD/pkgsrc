$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.10 2025/08/30 06:44:05 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2025-08-22 05:44:00.207667260 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -16,6 +16,8 @@ pdfium_patches += constexpr-template.pat
 
 pdfium_patches += system-abseil.diff
 
+pdfium_patches += pkgsrc.patch.1
+
 # https://pdfium-review.googlesource.com/c/pdfium/+/130970
 pdfium_patches += retrieve-MIME-type-from-PDF-attachments.patch.1
 
