$NetBSD: patch-external_pdfium_Library__pdfium.mk,v 1.1 2020/02/05 14:10:35 ryoon Exp $

* Do not conflict with external freetype2 on NetBSD etc.

--- external/pdfium/Library_pdfium.mk.orig	2020-01-22 23:14:16.000000000 +0000
+++ external/pdfium/Library_pdfium.mk
@@ -567,9 +567,9 @@ $(eval $(call gb_Library_use_externals,p
     icuuc \
 ))
 
-ifneq (,$(filter LINUX ANDROID,$(OS)))
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS ANDROID, $(OS)))
 $(eval $(call gb_Library_add_libs,pdfium,\
-    -ldl \
+    $(DLOPEN_LIBS) \
     -lrt \
 ))
 
