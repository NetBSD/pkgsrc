$NetBSD: patch-third-party_cmake_FindMySQL.cmake,v 1.1 2021/01/15 00:37:17 wiz Exp $

Find buildlink mysql include dir

--- third-party/cmake/FindMySQL.cmake.orig	2020-08-03 15:43:47.000000000 +0200
+++ third-party/cmake/FindMySQL.cmake	2020-09-02 14:47:44.451813388 +0200
@@ -28,32 +28,12 @@
 ##########################################################################
 
 
-FILE(GLOB _macports_include_dirs /opt/local/include/mysql*/mysql)
-
 #-------------- FIND MYSQL_INCLUDE_DIR ------------------
-FIND_PATH(MYSQL_INCLUDE_DIR mysql.h
-  $ENV{MYSQL_INCLUDE_DIR}
-  $ENV{MYSQL_DIR}/include
-  /usr/include/mysql
-  /usr/local/include/mysql
-  /usr/include/mariadb
-  /usr/local/include/mariadb
-  /opt/mysql/mysql/include
-  /opt/mysql/mysql/include/mysql
-  /opt/mysql/include
-  /opt/mariadb/include/mysql
-  /opt/local/include/mysql5
-  /usr/local/mysql/include
-  /usr/local/mysql/include/mysql
-  ${_macports_include_dirs}
-  $ENV{ProgramFiles}/MySQL/*/include
-  $ENV{SystemDrive}/MySQL/*/include
-  $ENV{ProgramFiles}/MariaDB*/include/mysql
-  $ENV{SystemDrive}/MariaDB*/include/mysql
+FIND_PATH(MYSQL_INCLUDE_DIR
+  NAMES mysql.h
+  PATH_SUFFIXES mysql
 )
 
-UNSET(_macports_include_dirs)
-
 #----------------- FIND MYSQL_LIB_DIR -------------------
 IF (WIN32)
   SET(MYSQL_CLIENT_LIBS libmysql)
