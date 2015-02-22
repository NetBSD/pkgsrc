$NetBSD: patch-sw_Executable__tiledrendering.mk,v 1.2 2015/02/22 08:15:01 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

--- sw/Executable_tiledrendering.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ sw/Executable_tiledrendering.mk
@@ -42,7 +42,7 @@ $(eval $(call gb_Executable_add_exceptio
     sw/qa/tiledrendering/tiledrendering \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 
 $(eval $(call gb_Executable_add_libs,tiledrendering,\
 	-lm \
