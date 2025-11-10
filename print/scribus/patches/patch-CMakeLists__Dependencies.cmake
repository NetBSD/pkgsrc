$NetBSD: patch-CMakeLists__Dependencies.cmake,v 1.1 2025/11/10 13:54:53 wiz Exp $

* CMAKE_MODULE_PATH is not a single value, it can be a list.

--- CMakeLists_Dependencies.cmake.orig	2025-01-25 21:58:37.000000000 +0000
+++ CMakeLists_Dependencies.cmake
@@ -125,8 +125,8 @@ if (WIN32)
 	# On win32 we can use Qt's zlib and libpng, so we use some
 	# custom cmake includes. This permits us to honour the
 	# USE_QT_ZLIB_PNGLIB flag if passed.
-	set(PNG_DIR ${CMAKE_MODULE_PATH})
-	set(ZLIB_DIR ${CMAKE_MODULE_PATH})
+	set(PNG_DIR "${CMAKE_SOURCE_DIR}/cmake/modules")
+	set(ZLIB_DIR "${CMAKE_SOURCE_DIR}/cmake/modules")
 endif()
 #>> PNG
 #<< ZLIB
@@ -180,6 +180,7 @@ endif()
 #>> FreeType2
 
 set(cairo_DIR ${CMAKE_MODULE_PATH})
+set(cairo_DIR "${CMAKE_SOURCE_DIR}/cmake/modules")
 find_package(cairo REQUIRED)
 if(cairo_FOUND)
 	set(HAVE_CAIRO ON)
@@ -222,7 +223,7 @@ endif()
 #>>JPEG XL
 
 #<<LittleCMS
-set(LCMS_DIR ${CMAKE_MODULE_PATH})
+set(LCMS_DIR "${CMAKE_SOURCE_DIR}/cmake/modules")
 find_package(LCMS2 REQUIRED)
 if(LCMS2_FOUND)
 	set(HAVE_LCMS2 ON)
@@ -277,7 +278,7 @@ endif()
 
 #<< GraphicsMagick for image import
 if (WANT_GRAPHICSMAGICK)
-	set(GMAGICK_DIR ${CMAKE_MODULE_PATH})
+	set(GMAGICK_DIR "${CMAKE_SOURCE_DIR}/cmake/modules")
 	pkg_check_modules(GMAGICK GraphicsMagick)
 	# find_package(GMAGICK)
 	if(GMAGICK_FOUND)
