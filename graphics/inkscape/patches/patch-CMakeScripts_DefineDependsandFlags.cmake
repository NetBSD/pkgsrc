$NetBSD: patch-CMakeScripts_DefineDependsandFlags.cmake,v 1.1 2017/09/09 21:48:56 prlw1 Exp $

Support poppler 0.58
https://gitlab.com/inkscape/inkscape/commit/9418824967eb4c53371ef8588243fed4cab496e0

--- CMakeScripts/DefineDependsandFlags.cmake.orig	2017-02-13 23:46:57.000000000 +0000
+++ CMakeScripts/DefineDependsandFlags.cmake
@@ -126,6 +126,10 @@ if(ENABLE_POPPLER)
 		POPPLER_VERSION VERSION_EQUAL   "0.29.0")
 	    set(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API ON)
 	endif()
+	if(POPPLER_VERSION VERSION_GREATER "0.58.0" OR
+		POPPLER_VERSION VERSION_EQUAL   "0.58.0")
+            set(POPPLER_NEW_OBJECT_API ON)
+	endif()
     else()
 	set(ENABLE_POPPLER_CAIRO OFF)
     endif()
