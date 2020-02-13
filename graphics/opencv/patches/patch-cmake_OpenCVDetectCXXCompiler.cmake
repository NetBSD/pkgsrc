$NetBSD: patch-cmake_OpenCVDetectCXXCompiler.cmake,v 1.2 2020/02/13 09:23:46 adam Exp $

Rely on pkgsrc to set architeture, see CONFIGURE_ENV.

--- cmake/OpenCVDetectCXXCompiler.cmake.orig	2019-12-19 15:16:47.000000000 +0000
+++ cmake/OpenCVDetectCXXCompiler.cmake
@@ -84,6 +84,10 @@ endif()
 message(STATUS "Detected processor: ${CMAKE_SYSTEM_PROCESSOR}")
 if(OPENCV_SKIP_SYSTEM_PROCESSOR_DETECTION)
   # custom setup: required variables are passed through cache / CMake's command-line
+elseif("$ENV{MACHINE_ARCH}" MATCHES "x86_64")
+  set(X86_64 1)
+elseif("$ENV{MACHINE_ARCH}" MATCHES "i386")
+  set(X86 1)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "amd64.*|x86_64.*|AMD64.*")
   set(X86_64 1)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i686.*|i386.*|x86.*")
