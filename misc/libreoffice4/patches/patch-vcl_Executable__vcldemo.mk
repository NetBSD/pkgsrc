$NetBSD: patch-vcl_Executable__vcldemo.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

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
