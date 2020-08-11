$NetBSD: patch-external_skia_Library__skia.mk,v 1.1 2020/08/11 16:07:39 ryoon Exp $

--- external/skia/Library_skia.mk.orig	2020-07-29 19:29:17.000000000 +0000
+++ external/skia/Library_skia.mk
@@ -66,10 +66,10 @@ $(eval $(call gb_Library_use_externals,s
     libpng \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
 $(eval $(call gb_Library_add_libs,skia,\
     -lm \
-    -ldl \
+    $(DLOPEN_LIBS) \
     -lX11-xcb \
     -lX11 \
 ))
