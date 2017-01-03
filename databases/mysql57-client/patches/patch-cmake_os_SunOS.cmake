$NetBSD: patch-cmake_os_SunOS.cmake,v 1.1 2017/01/03 12:27:27 jperkin Exp $

Do not attempt to detect ISA, it conflicts with wrappers.

--- cmake/os/SunOS.cmake.orig	2016-11-28 13:32:52.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -61,6 +61,7 @@ ADD_DEFINITIONS(-D__EXTENSIONS__)
 # http://docs.oracle.com/cd/E19455-01/806-5257/6je9h033k/index.html
 ADD_DEFINITIONS(-D_POSIX_PTHREAD_SEMANTICS -D_REENTRANT -D_PTHREADS)
 
+IF (0)
 IF (NOT "${CMAKE_C_FLAGS}${CMAKE_CXX_FLAGS}" MATCHES "-m32|-m64")
   EXECUTE_PROCESS(COMMAND isainfo -b
     OUTPUT_VARIABLE ISAINFO_B
@@ -75,6 +76,7 @@ IF (NOT "${CMAKE_C_FLAGS}${CMAKE_CXX_FLA
     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m${ISAINFO_B}")
   ENDIF()
 ENDIF()
+ENDIF()
 
 # On  Solaris, use of intrinsics will screw the lib search logic
 # Force using -lm, so rint etc are found.
