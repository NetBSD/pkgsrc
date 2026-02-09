$NetBSD: patch-external_pdfium_Library__pdfium.mk,v 1.5 2026/02/09 16:59:59 ryoon Exp $

We also want to link against librt on Solaris and BSD.

--- external/pdfium/Library_pdfium.mk.orig	2026-01-27 21:11:38.000000000 +0000
+++ external/pdfium/Library_pdfium.mk
@@ -582,6 +582,11 @@ $(eval $(call gb_Library_add_libs,pdfium,\
 ifneq (,$(filter LINUX ANDROID,$(OS)))
 $(eval $(call gb_Library_add_libs,pdfium,\
     -ldl \
+))
+endif
+
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS ANDROID, $(OS)))
+$(eval $(call gb_Library_add_libs,pdfium,\
     -lrt \
 ))
 
@@ -715,7 +720,7 @@ endif
 ))
 endif
 
-ifneq (,$(filter LINUX FREEBSD OPENBSD,$(OS)))
+ifneq (,$(filter LINUX %BSD SOLARIS,$(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/linux/fx_linux_impl \
