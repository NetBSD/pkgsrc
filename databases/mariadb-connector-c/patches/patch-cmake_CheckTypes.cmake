$NetBSD: patch-cmake_CheckTypes.cmake,v 1.1 2018/04/13 08:04:14 fhajny Exp $

Using socket types needs libsocket on at least SunOS.

--- cmake/CheckTypes.cmake.orig	2017-01-17 09:53:54.000000000 +0000
+++ cmake/CheckTypes.cmake
@@ -98,6 +98,7 @@ IF(WIN32)
 ELSE(WIN32)
   FOREACH(CHECK_TYPE "socklen_t" "size_t" "int")
     IF (NOT SOCKET_SIZE_TYPE)
+      SET(CMAKE_REQUIRED_LIBRARIES "${LIBSOCKET}")
       CHECK_C_SOURCE_COMPILES("
         #include <sys/socket.h>
         int main(int argc, char **argv)
