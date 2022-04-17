$NetBSD: patch-cmake_build__configurations_mysql__release.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- cmake/build_configurations/mysql_release.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ cmake/build_configurations/mysql_release.cmake
@@ -26,7 +26,7 @@ INCLUDE(CheckIncludeFiles)
 INCLUDE(CheckLibraryExists)
 
 OPTION(DEBUG_EXTNAME "" ON)
-OPTION(ENABLED_LOCAL_INFILE "" ON)
+OPTION(ENABLED_LOCAL_INFILE "" OFF)
 
 IF(NOT COMPILATION_COMMENT)
   SET(COMPILATION_COMMENT "MySQL Community Server (GPL)")
