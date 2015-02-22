$NetBSD: patch-desktop_Library__sofficeapp.mk,v 1.2 2015/02/22 08:15:01 ryoon Exp $

https://bugs.documentfoundation.org/show_bug.cgi?id=89551

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
