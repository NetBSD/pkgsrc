$NetBSD: patch-external_pdfium_Library__pdfium.mk,v 1.3 2021/08/22 02:41:50 ryoon Exp $

* Do not conflict with external freetype2 on NetBSD etc.

--- external/pdfium/Library_pdfium.mk.orig	2021-08-16 19:56:28.000000000 +0000
+++ external/pdfium/Library_pdfium.mk
@@ -566,9 +566,9 @@ $(eval $(call gb_Library_use_externals,p
     icuuc \
 ))
 
-ifneq (,$(filter LINUX ANDROID,$(OS)))
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS ANDROID, $(OS)))
 $(eval $(call gb_Library_add_libs,pdfium,\
-    -ldl \
+    $(DLOPEN_LIBS) \
     -lrt \
 ))
 
@@ -685,7 +685,7 @@ $(eval $(call gb_Library_add_generated_e
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/linux/fx_linux_impl \
