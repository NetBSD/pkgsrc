$NetBSD: patch-libreofficekit_Library__libreofficekitgtk.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- libreofficekit/Library_libreofficekitgtk.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ libreofficekit/Library_libreofficekitgtk.mk
@@ -26,4 +26,10 @@ $(eval $(call gb_Library_add_libs,libreo
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Library_add_libs,libreofficekitgtk,\
+    -lm \
+))
+endif
+
 # vim: set noet sw=4 ts=4:
