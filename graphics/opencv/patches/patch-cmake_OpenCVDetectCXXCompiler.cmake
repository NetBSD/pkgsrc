$NetBSD: patch-cmake_OpenCVDetectCXXCompiler.cmake,v 1.1 2015/10/08 17:45:59 fhajny Exp $

Rely on pkgsrc to set architeture, see CONFIGURE_ENV.

--- cmake/OpenCVDetectCXXCompiler.cmake.orig	2015-06-03 17:21:34.000000000 +0000
+++ cmake/OpenCVDetectCXXCompiler.cmake
@@ -103,6 +103,10 @@ if(MSVC64 OR MINGW64)
   set(X86_64 1)
 elseif(MINGW OR (MSVC AND NOT CMAKE_CROSSCOMPILING))
   set(X86 1)
+elseif("$ENV{MACHINE_ARCH}" MATCHES "x86_64")
+  set(X86_64 1)
+elseif("$ENV{MACHINE_ARCH}" MATCHES "i386")
+  set(X86 1)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "amd64.*|x86_64.*|AMD64.*")
   set(X86_64 1)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i686.*|i386.*|x86.*|amd64.*|AMD64.*")
