$NetBSD: patch-external_pdfium_Library__pdfium.mk,v 1.4 2023/08/06 10:41:42 nia Exp $

We also want to link against librt on Solaris and BSD.

--- external/pdfium/Library_pdfium.mk.orig	2023-07-12 17:23:19.000000000 +0000
+++ external/pdfium/Library_pdfium.mk
@@ -587,6 +587,11 @@ $(eval $(call gb_Library_use_externals,p
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
 
@@ -719,7 +724,7 @@ $(eval $(call gb_Library_add_generated_e
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/linux/fx_linux_impl \
