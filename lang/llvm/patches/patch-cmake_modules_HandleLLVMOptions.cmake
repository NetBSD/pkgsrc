$NetBSD: patch-cmake_modules_HandleLLVMOptions.cmake,v 1.2 2019/06/02 08:35:55 adam Exp $

DragonflyBSD support

--- cmake/modules/HandleLLVMOptions.cmake.orig	2018-12-19 18:01:42.000000000 +0000
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -137,6 +137,7 @@ endif()
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
 if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR WIN32 OR CYGWIN OR
+        ${CMAKE_SYSTEM_NAME} MATCHES "DragonFly" OR
         ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" OR
 	${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD" OR
 	${CMAKE_SYSTEM_NAME} MATCHES "DragonFly") AND
