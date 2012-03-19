$NetBSD: patch-cmake_modules_FindSqlite.cmake,v 1.1 2012/03/19 11:39:16 markd Exp $

If pkg-config provides a sqlite version, use it in preference

PC_SQLITE_{INCLUDE,LIB}DIR may be null if in default path so need to 
include default path in search.

--- cmake/modules/FindSqlite.cmake.orig	2011-05-07 09:22:49.000000000 +0000
+++ cmake/modules/FindSqlite.cmake
@@ -38,13 +38,11 @@ if(PC_SQLITE_FOUND)
   find_path(SQLITE_INCLUDE_DIR
             NAMES sqlite3.h
             PATHS ${PC_SQLITE_INCLUDEDIR}
-            NO_DEFAULT_PATH
            )
 
   find_library(SQLITE_LIBRARIES
                NAMES sqlite3
                PATHS ${PC_SQLITE_LIBDIR}
-               NO_DEFAULT_PATH
               )
 else(PC_SQLITE_FOUND)
   find_path(SQLITE_INCLUDE_DIR
@@ -67,22 +65,26 @@ else( UNIX )
   set( SQLITE_STATIC_LIBRARIES ${SQLITE_LIBRARIES} )
 endif( UNIX )
 
-if(EXISTS ${SQLITE_INCLUDE_DIR}/sqlite3.h)
-  file(READ ${SQLITE_INCLUDE_DIR}/sqlite3.h SQLITE3_H_CONTENT)
-  string(REGEX MATCH "SQLITE_VERSION[ ]*\"[0-9.]*\"\n" SQLITE_VERSION_MATCH "${SQLITE3_H_CONTENT}")
-
-  if(SQLITE_VERSION_MATCH)
-    string(REGEX REPLACE ".*SQLITE_VERSION[ ]*\"(.*)\"\n" "\\1" SQLITE_VERSION ${SQLITE_VERSION_MATCH})
-
-    if(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-        message(STATUS "Sqlite ${SQLITE_VERSION} was found, but at least version ${SQLITE_MIN_VERSION} is required")
-        set(SQLITE_VERSION_OK FALSE)
-    else(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-        set(SQLITE_VERSION_OK TRUE)
-    endif(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-
-  endif(SQLITE_VERSION_MATCH)
-
+if( PC_SQLITE_VERSION )
+  set( SQLITE_VERSION ${PC_SQLITE_VERSION})
+else( PC_SQLITE_VERSION )
+  if(EXISTS ${SQLITE_INCLUDE_DIR}/sqlite3.h)
+    file(READ ${SQLITE_INCLUDE_DIR}/sqlite3.h SQLITE3_H_CONTENT)
+    string(REGEX MATCH "SQLITE_VERSION[ ]*\"[0-9.]*\"\n" SQLITE_VERSION_MATCH "${SQLITE3_H_CONTENT}")
+
+    if(SQLITE_VERSION_MATCH)
+      string(REGEX REPLACE ".*SQLITE_VERSION[ ]*\"(.*)\"\n" "\\1" SQLITE_VERSION ${SQLITE_VERSION_MATCH})
+    endif(SQLITE_VERSION_MATCH)
+  endif()
+endif( PC_SQLITE_VERSION )
+
+if (SQLITE_VERSION)
+  if(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
+      message(STATUS "Sqlite ${SQLITE_VERSION} was found, but at least version ${SQLITE_MIN_VERSION} is required")
+      set(SQLITE_VERSION_OK FALSE)
+  else(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
+      set(SQLITE_VERSION_OK TRUE)
+  endif(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
 endif()
 
 include(FindPackageHandleStandardArgs)
