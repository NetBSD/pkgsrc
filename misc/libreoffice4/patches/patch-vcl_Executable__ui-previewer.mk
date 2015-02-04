$NetBSD: patch-vcl_Executable__ui-previewer.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

--- vcl/Executable_ui-previewer.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ vcl/Executable_ui-previewer.mk
@@ -34,7 +34,7 @@ $(eval $(call gb_Executable_add_exceptio
     vcl/source/uipreviewer/previewer \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 $(eval $(call gb_Executable_add_libs,ui-previewer,\
 	-lm \
 	-ldl \
