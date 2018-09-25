$NetBSD: patch-cmake_Modules_FindMySQL.cmake,v 1.1 2018/09/25 12:59:26 wiz Exp $

Fix detection of mysql library.

--- cmake/Modules/FindMySQL.cmake.orig	2013-09-14 10:09:01.000000000 +0000
+++ cmake/Modules/FindMySQL.cmake
@@ -21,7 +21,7 @@ FIND_PATH(MySQL_INCLUDE_DIR 
 
 # Library
 #SET(MySQL_NAMES mysqlclient mysqlclient_r)
-SET(MySQL_NAMES mysqlclient_r)
+SET(MySQL_NAMES mysqlclient_r mysqlclient)
 FIND_LIBRARY(MySQL_LIBRARY
   NAMES ${MySQL_NAMES}
   PATHS /usr/lib /usr/local/lib
