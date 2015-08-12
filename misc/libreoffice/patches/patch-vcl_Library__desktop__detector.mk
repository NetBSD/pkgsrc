$NetBSD: patch-vcl_Library__desktop__detector.mk,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- vcl/Library_desktop_detector.mk.orig	2015-07-31 00:32:43.000000000 +0000
+++ vcl/Library_desktop_detector.mk
@@ -71,4 +71,11 @@ $(eval $(call gb_Library_add_libs,deskto
 ))
 endif
 
+ifeq ($(OS),NETBSD)
+$(eval $(call gb_Library_add_libs,desktop_detector,\
+	-lm \
+	-lpthread \
+))
+endif
+
 # vim: set noet sw=4 ts=4:
