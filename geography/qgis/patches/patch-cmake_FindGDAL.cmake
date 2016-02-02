$NetBSD: patch-cmake_FindGDAL.cmake,v 1.1 2016/02/02 04:33:58 dbj Exp $

use FIND_LIBRARY instead of using a possibly multiple-valued
GDAL_LINK_DIRECTORIES_PATH as an absolute path

--- cmake/FindGDAL.cmake.orig	2016-01-15 12:00:55.000000000 +0000
+++ cmake/FindGDAL.cmake
@@ -152,16 +152,7 @@ ELSE(WIN32)
           STRING(REGEX REPLACE "[-][l]" "" GDAL_LIB_NAME ${GDAL_LIB_NAME_WITH_PREFIX} )
         ENDIF (GDAL_LIB_NAME_WITH_PREFIX)
 
-        IF (APPLE)
-          IF (NOT GDAL_LIBRARY)
-            # work around empty GDAL_LIBRARY left by framework check
-            # while still preserving user setting if given
-            # ***FIXME*** need to improve framework check so below not needed
-            SET(GDAL_LIBRARY ${GDAL_LINK_DIRECTORIES}/lib${GDAL_LIB_NAME}.dylib CACHE STRING INTERNAL FORCE)
-          ENDIF (NOT GDAL_LIBRARY)
-        ELSE (APPLE)
-          SET(GDAL_LIBRARY ${GDAL_LINK_DIRECTORIES}/lib${GDAL_LIB_NAME}.so CACHE STRING INTERNAL)
-        ENDIF (APPLE)
+        FIND_LIBRARY(GDAL_LIBRARY NAMES ${GDAL_LIB_NAME} PATHS ${GDAL_LINK_DIRECTORIES})
       
       ELSE(GDAL_CONFIG)
         MESSAGE("FindGDAL.cmake: gdal-config not found. Please set it manually. GDAL_CONFIG=${GDAL_CONFIG}")
