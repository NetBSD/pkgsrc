$NetBSD: patch-vcl_Executable__ui-previewer.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

--- vcl/Executable_ui-previewer.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Executable_ui-previewer.mk
@@ -48,4 +48,17 @@ $(eval $(call gb_Executable_use_static_l
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,ui-previewer,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,ui-previewer,\
+	glxtest \
+))
+endif
+
 # vim: set noet sw=4 ts=4:
