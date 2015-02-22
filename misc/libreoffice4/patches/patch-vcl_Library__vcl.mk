$NetBSD: patch-vcl_Library__vcl.mk,v 1.2 2015/02/22 08:15:01 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

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
