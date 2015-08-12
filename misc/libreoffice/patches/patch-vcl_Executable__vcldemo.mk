$NetBSD: patch-vcl_Executable__vcldemo.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Executable_vcldemo.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Executable_vcldemo.mk
@@ -55,4 +55,17 @@ $(eval $(call gb_Executable_use_static_l
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,vcldemo,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,vcldemo,\
+	glxtest \
+))
+endif
+
 # vim: set noet sw=4 ts=4:
