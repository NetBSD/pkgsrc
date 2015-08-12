$NetBSD: patch-desktop_Library__sofficeapp.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

--- desktop/Library_sofficeapp.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ desktop/Library_sofficeapp.mk
@@ -23,6 +23,13 @@ $(eval $(call gb_Library_add_libs,soffic
     ) \
 ))
 
+$(eval $(call gb_Library_add_libs,sofficeapp,\
+    $(if $(filter $(OS),NETBSD), \
+        -ldl \
+        -lpthread \
+    ) \
+))
+
 $(eval $(call gb_Library_use_external,sofficeapp,boost_headers))
 
 $(eval $(call gb_Library_use_custom_headers,sofficeapp,\
@@ -117,6 +124,19 @@ $(eval $(call gb_Library_add_libs,soffic
     -lX11 \
 ))
 endif
+
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Library_use_static_libraries,sofficeapp,\
+    glxtest \
+))
+
+$(eval $(call gb_Library_add_libs,sofficeapp,\
+	-lm \
+	-lpthread \
+    -lGL \
+    -lX11 \
+))
+endif
 endif
 
 # LibreOfficeKit bits
