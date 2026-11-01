$NetBSD: patch-cmake_nanobind-config.cmake,v 1.2 2026/11/01 20:34:54 wiz Exp $

NetBSD's x86_64 runtime linker does not support the TLSDESC
thread-local storage ABI (R_X86_64_TLSDESC, relocation type 36).
Limit the check to Linux systems.

https://github.com/wjakob/nanobind/pull/1462

--- cmake/nanobind-config.cmake.orig	2026-09-29 09:19:48.000000000 +0000
+++ cmake/nanobind-config.cmake
@@ -113,7 +113,7 @@
 # Probe for the faster TLSDESC thread-local storage ABI (Linux/x86_64)
 # ---------------------------------------------------------------------------
 
-if (NOT (MSVC OR WIN32 OR APPLE))
+if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
   include(CheckCXXCompilerFlag)
   check_cxx_compiler_flag(-mtls-dialect=gnu2 NB_HAS_MTLS_GNU2)
 endif()
