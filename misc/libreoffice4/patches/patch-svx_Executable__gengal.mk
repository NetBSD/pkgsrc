$NetBSD: patch-svx_Executable__gengal.mk,v 1.2 2015/02/22 08:15:01 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

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
