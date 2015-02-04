$NetBSD: patch-sw_Executable__tiledrendering.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

--- sw/Executable_tiledrendering.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ sw/Executable_tiledrendering.mk
@@ -42,7 +42,7 @@ $(eval $(call gb_Executable_add_exceptio
     sw/qa/tiledrendering/tiledrendering \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 
 $(eval $(call gb_Executable_add_libs,tiledrendering,\
 	-lm \
