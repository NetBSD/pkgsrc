$NetBSD: patch-cmake_os_SunOS.cmake,v 1.2 2017/04/11 20:49:15 adam Exp $

Do not attempt to detect ISA, it conflicts with wrappers.

--- cmake/os/SunOS.cmake.orig	2017-03-18 07:45:14.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -62,6 +62,7 @@ ADD_DEFINITIONS(-D__EXTENSIONS__)
 # http://docs.oracle.com/cd/E19455-01/806-5257/6je9h033k/index.html
 ADD_DEFINITIONS(-D_POSIX_PTHREAD_SEMANTICS -D_REENTRANT -D_PTHREADS)
 
+IF (0)
 IF (NOT "${CMAKE_C_FLAGS}${CMAKE_CXX_FLAGS}" MATCHES "-m32|-m64")
   EXECUTE_PROCESS(COMMAND isainfo -b
     OUTPUT_VARIABLE ISAINFO_B
@@ -86,6 +87,7 @@ ELSE()
     SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -m64")
   ENDIF()
 ENDIF()
+ENDIF()
 
 # On  Solaris, use of intrinsics will screw the lib search logic
 # Force using -lm, so rint etc are found.
