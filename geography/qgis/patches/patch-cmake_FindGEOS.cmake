$NetBSD: patch-cmake_FindGEOS.cmake,v 1.2 2016/02/02 04:33:58 dbj Exp $

use FIND_LIBRARY instead of using a possibly multiple-valued
GEOS_LINK_DIRECTORIES_PATH as an absolute path

--- cmake/FindGEOS.cmake.orig	2016-01-15 12:00:55.000000000 +0000
+++ cmake/FindGEOS.cmake
@@ -140,16 +140,7 @@ ELSE(WIN32)
         ENDIF (GEOS_LIB_NAME_WITH_PREFIX)
         #MESSAGE("DBG  GEOS_LIB_NAME=${GEOS_LIB_NAME}")
 
-        IF (APPLE)
-          IF (NOT GEOS_LIBRARY)
-            # work around empty GEOS_LIBRARY left by framework check
-            # while still preserving user setting if given
-            # ***FIXME*** need to improve framework check so below not needed
-            SET(GEOS_LIBRARY ${GEOS_LINK_DIRECTORIES}/lib${GEOS_LIB_NAME}.dylib CACHE STRING INTERNAL FORCE)
-          ENDIF (NOT GEOS_LIBRARY)
-        ELSE (APPLE)
-          SET(GEOS_LIBRARY ${GEOS_LINK_DIRECTORIES}/lib${GEOS_LIB_NAME}.so CACHE STRING INTERNAL)
-        ENDIF (APPLE)
+        FIND_LIBRARY(GEOS_LIBRARY NAMES ${GEOS_LIB_NAME} PATHS ${GEOS_LINK_DIRECTORIES})
         #MESSAGE("DBG  GEOS_LIBRARY=${GEOS_LIBRARY}")
 
       ELSE(GEOS_CONFIG)
