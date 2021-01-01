$NetBSD: patch-external_pdfium_Library__pdfium.mk,v 1.2 2021/01/01 13:17:44 ryoon Exp $

* Do not conflict with external freetype2 on NetBSD etc.

--- external/pdfium/Library_pdfium.mk.orig	2020-12-09 18:56:14.000000000 +0000
+++ external/pdfium/Library_pdfium.mk
@@ -577,9 +577,9 @@ $(eval $(call gb_Library_use_externals,p
     icuuc \
 ))
 
-ifneq (,$(filter LINUX ANDROID,$(OS)))
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS ANDROID, $(OS)))
 $(eval $(call gb_Library_add_libs,pdfium,\
-    -ldl \
+    $(DLOPEN_LIBS) \
     -lrt \
 ))
 
@@ -682,7 +682,7 @@ $(eval $(call gb_Library_add_generated_e
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/fx_ge_linux \
