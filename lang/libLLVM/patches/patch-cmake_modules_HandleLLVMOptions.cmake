$NetBSD: patch-cmake_modules_HandleLLVMOptions.cmake,v 1.1 2016/12/10 22:30:27 maya Exp $

DragonflyBSD support

--- cmake/modules/HandleLLVMOptions.cmake.orig 2016-01-06 19:05:19.000000000 +0000
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -132,6 +132,7 @@ endif()
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
 if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR WIN32 OR CYGWIN OR
+        ${CMAKE_SYSTEM_NAME} MATCHES "DragonFly" OR
         ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" OR
         ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD") AND
    NOT LLVM_USE_SANITIZER)
