$NetBSD: patch-vcl_Executable__mtfdemo.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Executable_mtfdemo.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Executable_mtfdemo.mk
@@ -54,4 +54,17 @@ $(eval $(call gb_Executable_use_static_l
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,mtfdemo,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,mtfdemo,\
+	glxtest \
+))
+endif
+
 # vim: set noet sw=4 ts=4:
