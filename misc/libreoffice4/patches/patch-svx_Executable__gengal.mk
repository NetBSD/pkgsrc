$NetBSD: patch-svx_Executable__gengal.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

--- svx/Executable_gengal.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ svx/Executable_gengal.mk
@@ -61,7 +61,7 @@ $(eval $(call gb_Executable_use_system_w
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 $(eval $(call gb_Executable_add_libs,gengal,\
 	-ldl \
 	-lpthread \
