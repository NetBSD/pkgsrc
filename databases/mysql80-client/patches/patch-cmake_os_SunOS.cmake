$NetBSD: patch-cmake_os_SunOS.cmake,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* Do not attempt to detect ISA, it conflicts with wrappers.

--- cmake/os/SunOS.cmake.orig	2019-12-09 19:53:17.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -32,6 +32,7 @@ ELSE()
   SET(SOLARIS_INTEL 1)
 ENDIF()
 
+IF(0)
 IF (NOT "${CMAKE_C_FLAGS}${CMAKE_CXX_FLAGS}" MATCHES "-m32|-m64")
   IF(NOT FORCE_UNSUPPORTED_COMPILER)
     MESSAGE("Adding -m64")
@@ -41,6 +42,7 @@ IF (NOT "${CMAKE_C_FLAGS}${CMAKE_CXX_FLA
     STRING_APPEND(CMAKE_CXX_LINK_FLAGS " -m64")
   ENDIF()
 ENDIF()
+ENDIF()
 
 INCLUDE(CheckTypeSize)
 CHECK_TYPE_SIZE("void *" SIZEOF_VOIDP)
