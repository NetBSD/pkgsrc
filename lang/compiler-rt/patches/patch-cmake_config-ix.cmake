$NetBSD: patch-cmake_config-ix.cmake,v 1.8 2026/04/16 06:33:51 wiz Exp $

Disable components that aren't ready for SunOS yet.

--- cmake/config-ix.cmake.orig	2025-10-21 08:14:55.000000000 +0000
+++ cmake/config-ix.cmake
@@ -760,7 +760,7 @@ set(COMPILER_RT_SANITIZERS_TO_BUILD all
 list_replace(COMPILER_RT_SANITIZERS_TO_BUILD all "${ALL_SANITIZERS}")
 
 if (SANITIZER_COMMON_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|NetBSD|Fuchsia|SunOS|Haiku" OR
+    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|NetBSD|Fuchsia|Haiku" OR
     (OS_NAME MATCHES "Windows" AND NOT CYGWIN AND
         (NOT MINGW OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))))
   set(COMPILER_RT_HAS_SANITIZER_COMMON TRUE)
@@ -799,7 +799,7 @@ else()
   set(COMPILER_RT_HAS_RTSAN FALSE)
 endif()
 
-if (OS_NAME MATCHES "Linux|FreeBSD|Windows|NetBSD|SunOS")
+if (OS_NAME MATCHES "Linux|FreeBSD|Windows|NetBSD")
   set(COMPILER_RT_ASAN_HAS_STATIC_RUNTIME TRUE)
 else()
   set(COMPILER_RT_ASAN_HAS_STATIC_RUNTIME FALSE)
@@ -875,7 +875,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND UBSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD|Windows|Android|Fuchsia|SunOS|Haiku")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD|Windows|Android|Fuchsia|Haiku")
   set(COMPILER_RT_HAS_UBSAN TRUE)
 else()
   set(COMPILER_RT_HAS_UBSAN FALSE)
