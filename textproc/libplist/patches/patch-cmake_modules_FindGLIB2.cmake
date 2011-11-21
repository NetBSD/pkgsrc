$NetBSD: patch-cmake_modules_FindGLIB2.cmake,v 1.1.1.1 2011/11/21 18:51:37 shattered Exp $

Fix glib2 detection using macros from spectrum.im.

--- cmake/modules/FindGLIB2.cmake.orig	2010-04-18 13:30:19.000000000 +0000
+++ cmake/modules/FindGLIB2.cmake
@@ -1,15 +1,4 @@
-# - Try to find the GLIB2 libraries
-# Once done this will define
-#
-#  GLIB2_FOUND - system has glib2
-#  GLIB2_INCLUDE_DIR - the glib2 include directory
-#  GLIB2_LIBRARIES - glib2 library
-
-# Copyright (c) 2008 Laurent Montel, <montel@kde.org>
-#
-# Redistribution and use is allowed according to the terms of the BSD license.
-# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
-
+set(GLIB2_LIBRARIES "GLIB2_LIBRARIES-NOTFOUND")
 
 if(GLIB2_INCLUDE_DIR AND GLIB2_LIBRARIES)
     # Already in cache, be silent
@@ -17,35 +6,44 @@ if(GLIB2_INCLUDE_DIR AND GLIB2_LIBRARIES
 endif(GLIB2_INCLUDE_DIR AND GLIB2_LIBRARIES)
 
 if (NOT WIN32)
-   FIND_PACKAGE(PkgConfig)
-   PKG_CHECK_MODULES(PC_GLIB2 glib-2.0)
-   SET(GLIB2_DEFINITIONS ${PC_GLIB2_CFLAGS_OTHER})
+   find_package(PkgConfig REQUIRED)
+   pkg_check_modules(PKG_GLIB REQUIRED glib-2.0)
 endif(NOT WIN32)
 
 find_path(GLIB2_MAIN_INCLUDE_DIR glib.h
           PATH_SUFFIXES glib-2.0
-          PATHS ${_LibGLIB2IncDir} )
+          PATHS ${PKG_GLIB_INCLUDE_DIRS} )
 
 # search the glibconfig.h include dir under the same root where the library is found
-find_library(GLIB2_LIBRARIES 
-             NAMES glib-2.0 
-             PATHS ${_LibGLIB2LinkDir} )
-
-get_filename_component(glib2LibDir "${GLIB2_LIBRARIES}" PATH)
+find_library(GLIB2_LIBRARIES
+             NAMES glib-2.0
+             PATHS ${PKG_GLIB_LIBRARY_DIRS} )
+
+find_library(GLIB2_THREAD
+             NAMES gthread-2.0
+             PATHS ${PKG_GLIB_LIBRARY_DIRS} )
 
 find_path(GLIB2_INTERNAL_INCLUDE_DIR glibconfig.h
           PATH_SUFFIXES glib-2.0/include
-          PATHS ${_LibGLIB2IncDir} "${glib2LibDir}" ${CMAKE_SYSTEM_LIBRARY_PATH})
+          PATHS ${PKG_GLIB_INCLUDE_DIRS} ${PKG_GLIB_LIBRARIES} ${CMAKE_SYSTEM_LIBRARY_PATH})
+
+if(GLIB2_THREAD)
+	set(GLIB2_LIBRARIES ${GLIB2_LIBRARIES} ${GLIB2_THREAD})
+else(GLIB2_THREAD)
+	message( FATAL_ERROR "Could NOT find gthread-2.0" )
+endif(GLIB2_THREAD)
+
 
-set(GLIB2_INCLUDE_DIR "${GLIB2_MAIN_INCLUDE_DIR}")
+set(GLIB2_INCLUDE_DIR ${GLIB2_MAIN_INCLUDE_DIR})
 
 # not sure if this include dir is optional or required
 # for now it is optional
 if(GLIB2_INTERNAL_INCLUDE_DIR)
-  set(GLIB2_INCLUDE_DIR ${GLIB2_INCLUDE_DIR} "${GLIB2_INTERNAL_INCLUDE_DIR}")
+  set(GLIB2_INCLUDE_DIR ${GLIB2_INCLUDE_DIR} ${GLIB2_INTERNAL_INCLUDE_DIR})
+  set(GLIB2_FOUND TRUE)
 endif(GLIB2_INTERNAL_INCLUDE_DIR)
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(GLIB2  DEFAULT_MSG  GLIB2_LIBRARIES GLIB2_MAIN_INCLUDE_DIR)
 
-mark_as_advanced(GLIB2_INCLUDE_DIR GLIB2_LIBRARIES)
\ No newline at end of file
+mark_as_advanced(GLIB2_INCLUDE_DIR GLIB2_LIBRARIES)
