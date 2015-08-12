$NetBSD: patch-vcl_Library__vcl.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Library_vcl.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Library_vcl.mk
@@ -58,7 +58,7 @@ $(eval $(call gb_Library_use_custom_head
 ))
 
 $(eval $(call gb_Library_use_externals,vcl,\
-	$(if $(filter LINUX MACOSX,$(OS)), \
+	$(if $(filter LINUX MACOSX NETBSD,$(OS)), \
 		curl) \
 	jpeg \
 	$(if $(filter-out WNT,$(OS)), \
@@ -730,6 +730,19 @@ $(eval $(call gb_Library_add_exception_o
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Library_add_libs,vcl,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Library_add_exception_objects,vcl,\
+	vcl/opengl/x11/X11DeviceInfo \
+))
+endif
+
 # Runtime dependency for unit-tests
 $(eval $(call gb_Library_use_restarget,vcl,vcl))
 
