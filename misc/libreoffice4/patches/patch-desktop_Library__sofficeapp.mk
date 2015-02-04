$NetBSD: patch-desktop_Library__sofficeapp.mk,v 1.1 2015/02/04 18:19:34 ryoon Exp $

--- desktop/Library_sofficeapp.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ desktop/Library_sofficeapp.mk
@@ -94,7 +94,7 @@ $(eval $(call gb_Library_add_exception_o
     desktop/source/migration/migration \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUIBASE),unx)
 $(eval $(call gb_Library_use_static_libraries,sofficeapp,\
     glxtest \
 ))
