$NetBSD: patch-CMakeScripts_DefineDependsandFlags.cmake,v 1.2 2019/01/06 08:41:01 markd Exp $

support for poppler 0.72 from upstream by way of linuxfromscratch 

--- CMakeScripts/DefineDependsandFlags.cmake.orig	2018-03-11 20:38:09.000000000 +0000
+++ CMakeScripts/DefineDependsandFlags.cmake
@@ -116,18 +116,6 @@ if(ENABLE_POPPLER)
 		set(HAVE_POPPLER_GLIB ON)
 	    endif()
 	endif()
-	if(POPPLER_VERSION VERSION_GREATER "0.26.0" OR
-		POPPLER_VERSION VERSION_EQUAL   "0.26.0")
-	    set(POPPLER_EVEN_NEWER_COLOR_SPACE_API ON)
-	endif()
-	if(POPPLER_VERSION VERSION_GREATER "0.29.0" OR
-		POPPLER_VERSION VERSION_EQUAL   "0.29.0")
-	    set(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API ON)
-	endif()
-	if(POPPLER_VERSION VERSION_GREATER "0.58.0" OR
-		POPPLER_VERSION VERSION_EQUAL   "0.58.0")
-            set(POPPLER_NEW_OBJECT_API ON)
-	endif()
     else()
 	set(ENABLE_POPPLER_CAIRO OFF)
     endif()
