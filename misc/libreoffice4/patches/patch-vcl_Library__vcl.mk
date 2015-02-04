$NetBSD: patch-vcl_Library__vcl.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

--- vcl/Library_vcl.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ vcl/Library_vcl.mk
@@ -703,7 +703,7 @@ endif
 endif
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 $(eval $(call gb_Library_add_libs,vcl,\
 	-lm \
 	-ldl \
