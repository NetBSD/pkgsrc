$NetBSD: patch-cmake_FindPostgres.cmake,v 1.1 2016/02/02 04:33:58 dbj Exp $

use FIND_LIBRARY instead of assuming libpq location or naming scheme

--- cmake/FindPostgres.cmake.orig	2016-01-15 12:00:55.000000000 +0000
+++ cmake/FindPostgres.cmake
@@ -62,42 +62,7 @@ ELSE(WIN32)
       EXEC_PROGRAM(${POSTGRES_CONFIG}
         ARGS --libdir
         OUTPUT_VARIABLE PG_TMP)
-      IF (APPLE)
-        SET(POSTGRES_LIBRARY ${PG_TMP}/libpq.dylib CACHE STRING INTERNAL)
-      ELSEIF (CYGWIN)
-        EXEC_PROGRAM(${POSTGRES_CONFIG}
-        ARGS --libs
-        OUTPUT_VARIABLE PG_TMP)
-
-        STRING(REGEX MATCHALL "[-][L]([^ ;])+" _LDIRS "${PG_TMP}")
-        STRING(REGEX MATCHALL "[-][l]([^ ;])+" _LLIBS "${PG_TMP}")
-
-        FIND_LIBRARY(POSTGRES_LIBRARY NAMES pq PATHS /usr/lib /usr/local/lib)
-
-        SET(_DIRS)
-        FOREACH(_DIR ${_LDIRS})
-          STRING(REPLACE "-L" "" _DIR ${_DIR})
-          SET(_DIRS ${_DIRS} ${_DIR})
-        ENDFOREACH(_DIR ${_LDIRS})
-
-        SET(_LIBS)
-        FOREACH(_LIB ${_LLIBS})
-          STRING(REPLACE "-l" "" _LIB ${_LIB})
-          SET(_LIBS ${_LIBS} ${_LIB})
-        ENDFOREACH(_LIB ${_LDIRS})
-
-        FOREACH(_LIBNAME ${_LIBS})
-	  UNSET(PG_LIB CACHE)
-          FIND_LIBRARY(PG_LIB NAMES ${_LIBNAME} PATHS ${_DIRS} /usr/lib /usr/local/lib)
-	  IF(NOT PG_LIB)
-	    MESSAGE(FATAL "PostgreSQL dependency library ${_LIBNAME} not found")
-	  ENDIF(NOT PG_LIB)
-          SET(POSTGRES_LIBRARY ${POSTGRES_LIBRARY} ${PG_LIB})
-        ENDFOREACH(_LIBNAME ${_LIBS})
-
-      ELSE (CYGWIN)
-        SET(POSTGRES_LIBRARY ${PG_TMP}/libpq.so CACHE STRING INTERNAL)
-      ENDIF (APPLE)
+      FIND_LIBRARY(POSTGRES_LIBRARY pq PATHS ${PG_TMP})
     ENDIF(POSTGRES_CONFIG)
 
   ENDIF(UNIX)
