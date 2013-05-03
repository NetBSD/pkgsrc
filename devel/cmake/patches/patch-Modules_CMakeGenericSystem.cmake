$NetBSD: patch-Modules_CMakeGenericSystem.cmake,v 1.1 2013/05/03 00:58:07 mef Exp $

Correct Install PREFIX, see SUBST_CLASSES+= prefix in Makefile

--- Modules/CMakeGenericSystem.cmake.orig	2012-11-01 00:32:05.000000000 +0900
+++ Modules/CMakeGenericSystem.cmake	2013-05-01 23:45:47.000000000 +0900
@@ -166,7 +166,7 @@ endif()
 
 # Choose a default install prefix for this platform.
 if(CMAKE_HOST_UNIX)
-  set(CMAKE_INSTALL_PREFIX "/usr/local"
+  set(CMAKE_INSTALL_PREFIX "@PREFIX@"
     CACHE PATH "Install path prefix, prepended onto install directories.")
 else()
   GetDefaultWindowsPrefixBase(CMAKE_GENERIC_PROGRAM_FILES)
