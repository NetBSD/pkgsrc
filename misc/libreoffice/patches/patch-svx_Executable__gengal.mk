$NetBSD: patch-svx_Executable__gengal.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

--- svx/Executable_gengal.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ svx/Executable_gengal.mk
@@ -74,6 +74,17 @@ $(eval $(call gb_Executable_add_libs,gen
     -lGL \
     -lX11 \
 ))
+$(eval $(call gb_Executable_use_static_libraries,gengal,\
+	glxtest \
+))
+endif
+
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,gengal,\
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
 
 $(eval $(call gb_Executable_use_static_libraries,gengal,\
 	glxtest \
