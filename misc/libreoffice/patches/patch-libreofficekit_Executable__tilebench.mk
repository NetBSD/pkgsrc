$NetBSD: patch-libreofficekit_Executable__tilebench.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- libreofficekit/Executable_tilebench.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ libreofficekit/Executable_tilebench.mk
@@ -19,11 +19,20 @@ $(eval $(call gb_Executable_use_librarie
 	sal \
 ))
 
+ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,tilebench,\
     -lm \
     -ldl \
     -lpthread \
 ))
+endif
+
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,tilebench,\
+    -lm \
+    -lpthread \
+))
+endif
 
 $(eval $(call gb_Executable_add_exception_objects,tilebench,\
     libreofficekit/qa/tilebench/tilebench \
