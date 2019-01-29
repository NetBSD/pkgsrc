$NetBSD: patch-cmake_build__configurations_mysql__release.cmake,v 1.1.2.2 2019/01/29 13:01:46 bsiegert Exp $

Backport of https://github.com/mysql/mysql-server/commit/98ed3d8bc8ad724686d26c7bf98dced3bd1777be
Avoid disclosure of files from a client to a malicious server, described here:
https://gwillem.gitlab.io/2019/01/17/adminer-4.6.2-file-disclosure-vulnerability/

--- cmake/build_configurations/mysql_release.cmake.orig	2018-09-10 10:17:55.000000000 +0000
+++ cmake/build_configurations/mysql_release.cmake
@@ -19,7 +19,7 @@ INCLUDE(CheckIncludeFiles)
 INCLUDE(CheckLibraryExists)
 
 OPTION(DEBUG_EXTNAME "" ON)
-OPTION(ENABLED_LOCAL_INFILE "" ON)
+OPTION(ENABLED_LOCAL_INFILE "" OFF)
 
 IF(NOT COMPILATION_COMMENT)
   SET(COMPILATION_COMMENT "MySQL Community Server (GPL)")
