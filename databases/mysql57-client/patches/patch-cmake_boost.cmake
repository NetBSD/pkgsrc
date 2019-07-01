$NetBSD: patch-cmake_boost.cmake,v 1.11 2019/07/01 10:25:49 adam Exp $

Allow newer Boost.

--- cmake/boost.cmake.orig	2019-04-13 13:32:15.000000000 +0000
+++ cmake/boost.cmake
@@ -262,12 +262,7 @@ IF(NOT BOOST_MAJOR_VERSION EQUAL 10)
   COULD_NOT_FIND_BOOST()
 ENDIF()
 
-IF(NOT BOOST_MINOR_VERSION EQUAL 59)
-  MESSAGE(WARNING "Boost minor version found is ${BOOST_MINOR_VERSION} "
-    "we need 59"
-    )
-  COULD_NOT_FIND_BOOST()
-ENDIF()
+
 
 MESSAGE(STATUS "BOOST_INCLUDE_DIR ${BOOST_INCLUDE_DIR}")
 
