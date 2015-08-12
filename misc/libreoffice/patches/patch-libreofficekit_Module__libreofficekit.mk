$NetBSD: patch-libreofficekit_Module__libreofficekit.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- libreofficekit/Module_libreofficekit.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ libreofficekit/Module_libreofficekit.mk
@@ -28,4 +28,23 @@ endif # ($(ENABLE_GTK),)
 
 endif # ($(OS),LINUX)
 
+ifeq ($(OS),NETBSD)
+
+$(eval $(call gb_Module_add_subsequentcheck_targets,libreofficekit,\
+    CppunitTest_libreofficekit_tiledrendering \
+))
+
+ifneq ($(ENABLE_GTK),)
+$(eval $(call gb_Module_add_targets,libreofficekit,\
+    Library_libreofficekitgtk \
+    Executable_gtktiledviewer \
+))
+
+$(eval $(call gb_Module_add_targets,libreofficekit,\
+    Executable_tilebench \
+))
+endif # ($(ENABLE_GTK),)
+
+endif # ($(OS),NETBSD)
+
 # vim: set ts=4 sw=4 et:
