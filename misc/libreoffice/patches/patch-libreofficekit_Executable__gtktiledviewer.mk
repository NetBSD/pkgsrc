$NetBSD: patch-libreofficekit_Executable__gtktiledviewer.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- libreofficekit/Executable_gtktiledviewer.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ libreofficekit/Executable_gtktiledviewer.mk
@@ -39,6 +39,13 @@ $(eval $(call gb_Executable_add_libs,gtk
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Executable_add_libs,gtktiledviewer,\
+    -lm \
+    -lpthread \
+))
+endif
+
 $(eval $(call gb_Executable_add_exception_objects,gtktiledviewer,\
     libreofficekit/qa/gtktiledviewer/gtktiledviewer \
 ))
