$NetBSD: patch-external_pdfium_UnpackedTarball__pdfium.mk,v 1.6 2021/08/22 02:41:50 ryoon Exp $

* Support pkgsrc and NetBSD

--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2021-08-16 19:56:28.000000000 +0000
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -18,6 +18,8 @@ pdfium_patches += c++20-comparison.patch
 pdfium_patches += cg-instead-of-carbon.patch.1
 # Android NDK 19 - that is known to work well - does not have 2 defines
 pdfium_patches += AndroidNDK19.patch.1
+# NetBSD support
+pdfium_patches += pkgsrc.patch.1
 
 # Work around <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94141> "c++20 rewritten operator==
 # recursive call mixing friend and external operators for template class" in GCC with
