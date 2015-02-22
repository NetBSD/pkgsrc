$NetBSD: patch-vcl_Executable__vcldemo.mk,v 1.2 2015/02/22 08:15:01 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

--- vcl/Executable_vcldemo.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ vcl/Executable_vcldemo.mk
@@ -42,7 +42,7 @@ $(eval $(call gb_Executable_use_static_l
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 $(eval $(call gb_Executable_add_libs,vcldemo,\
 	-lm \
 	-ldl \
