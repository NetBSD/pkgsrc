$NetBSD: patch-cmake_modules_FindSqlite.cmake,v 1.2 2014/11/13 09:44:02 markd Exp $

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
