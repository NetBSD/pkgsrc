$NetBSD: patch-external_skia_Library__skia.mk,v 1.3 2023/10/15 07:26:24 ryoon Exp $

We want to link against libm and libX11 on every Unix, but libdl only on
Linux.

--- external/skia/Library_skia.mk.orig	2023-08-08 19:49:18.000000000 +0000
+++ external/skia/Library_skia.mk
@@ -98,10 +98,21 @@ $(eval $(call gb_Library_use_externals,s
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
+ifeq ($(OS), $(filter NETBSD, $(OS)))
+$(eval $(call gb_Library_add_libs,skia,\
+    -ljemalloc \
+))
+endif
+
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
+$(eval $(call gb_Library_add_libs,skia,\
+    -lm \
     -lX11-xcb \
     -lX11 \
 ))
