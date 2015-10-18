$NetBSD: patch-CMakeModules_FindPNG.cmake,v 1.1 2015/10/18 15:56:56 adam Exp $

Fix PNG detection.

--- CMakeModules/FindPNG.cmake.orig	2014-06-05 08:39:26.000000000 +0000
+++ CMakeModules/FindPNG.cmake
@@ -33,7 +33,7 @@ IF (ZLIB_FOUND)
 
   find_library_with_debug(PNG_LIBRARIES
     WIN32_DEBUG_POSTFIX d
-    NAMES png libpng libpng16 libpng16_static libpng15 libpng15_static libpng14 wxpng
+    NAMES png libpng png16 libpng16 libpng16_static libpng15 libpng15_static libpng14 wxpng
     PATHS ${SYSTEM_LIB_DIRS} ${SOURCE_BASE_DIR}/libpng/lib ${SOURCE_BASE_DIR}/lpng142/lib ${SOURCE_BASE_DIR}/lpng141/lib ${SOURCE_BASE_DIR}/lpng140/lib ${wxWidgets_LIB_DIR}
   )
 
