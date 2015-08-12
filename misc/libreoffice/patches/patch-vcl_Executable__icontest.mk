$NetBSD: patch-vcl_Executable__icontest.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Executable_icontest.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Executable_icontest.mk
@@ -37,6 +37,17 @@ $(eval $(call gb_Executable_add_libs,ico
 $(eval $(call gb_Executable_use_static_libraries,icontest,\
 	glxtest \
 ))
+else ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,icontest,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,icontest,\
+	glxtest \
+))
 else ifeq ($(OS),WNT)
 
 $(eval $(call gb_Executable_use_system_win32_libs,icontest,\
