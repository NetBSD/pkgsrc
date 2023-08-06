$NetBSD: patch-external_skia_Library__skia.mk,v 1.2 2023/08/06 10:41:42 nia Exp $

We want to link against libm and libX11 on every Unix, but libdl only on
Linux.

--- external/skia/Library_skia.mk.orig	2023-07-12 17:23:19.000000000 +0000
+++ external/skia/Library_skia.mk
@@ -96,10 +96,15 @@ $(eval $(call gb_Library_use_externals,s
     libpng \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX, $(OS)))
 $(eval $(call gb_Library_add_libs,skia,\
-    -lm \
     -ldl \
+))
+endif
+
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
+$(eval $(call gb_Library_add_libs,skia,\
+    -lm \
     -lX11-xcb \
     -lX11 \
 ))
