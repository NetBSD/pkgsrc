$NetBSD: patch-cmake_Modules_FindLibSSH.cmake,v 1.1 2021/01/13 09:40:40 nia Exp $

Fix detecting the libssh version in newer releases.

--- cmake/Modules/FindLibSSH.cmake.orig	2013-10-18 13:11:09.000000000 +0000
+++ cmake/Modules/FindLibSSH.cmake
@@ -58,15 +58,15 @@ else (LIBSSH_LIBRARIES AND LIBSSH_INCLUD
     )
 
     if (LibSSH_FIND_VERSION)
-      file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_MAJOR
+      file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh_version.h LIBSSH_VERSION_MAJOR
         REGEX "#define[ ]+LIBSSH_VERSION_MAJOR[ ]+[0-9]+")
       # Older versions of libssh like libssh-0.2 have LIBSSH_VERSION but not LIBSSH_VERSION_MAJOR
       if (LIBSSH_VERSION_MAJOR)
         string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_MAJOR ${LIBSSH_VERSION_MAJOR})
-	file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_MINOR
+	file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh_version.h LIBSSH_VERSION_MINOR
           REGEX "#define[ ]+LIBSSH_VERSION_MINOR[ ]+[0-9]+")
 	string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_MINOR ${LIBSSH_VERSION_MINOR})
-	file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_PATCH
+	file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh_version.h LIBSSH_VERSION_PATCH
           REGEX "#define[ ]+LIBSSH_VERSION_MICRO[ ]+[0-9]+")
 	string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_PATCH ${LIBSSH_VERSION_PATCH})
 
@@ -75,7 +75,7 @@ else (LIBSSH_LIBRARIES AND LIBSSH_INCLUD
 	include(FindPackageVersionCheck)
 	find_package_version_check(LibSSH DEFAULT_MSG)
       else (LIBSSH_VERSION_MAJOR)
-        message(STATUS "LIBSSH_VERSION_MAJOR not found in ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h, assuming libssh is too old")
+        message(STATUS "LIBSSH_VERSION_MAJOR not found in ${LIBSSH_INCLUDE_DIR}/libssh/libssh_version.h, assuming libssh is too old")
         set(LIBSSH_FOUND FALSE)
       endif (LIBSSH_VERSION_MAJOR)
     endif (LibSSH_FIND_VERSION)
