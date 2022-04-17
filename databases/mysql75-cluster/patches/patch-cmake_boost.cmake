$NetBSD: patch-cmake_boost.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- cmake/boost.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ cmake/boost.cmake
@@ -269,13 +269,6 @@ IF(NOT BOOST_MAJOR_VERSION EQUAL 10)
   COULD_NOT_FIND_BOOST()
 ENDIF()
 
-IF(NOT BOOST_MINOR_VERSION EQUAL 59)
-  MESSAGE(WARNING "Boost minor version found is ${BOOST_MINOR_VERSION} "
-    "we need 59"
-    )
-  COULD_NOT_FIND_BOOST()
-ENDIF()
-
 MESSAGE(STATUS "BOOST_INCLUDE_DIR ${BOOST_INCLUDE_DIR}")
 
 # We have a limited set of patches/bugfixes here:
