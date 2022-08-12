$NetBSD: patch-cmake_config-ix.cmake,v 1.5 2022/08/12 08:58:41 pin Exp $

Disable components that aren't ready for SunOS yet.

--- cmake/config-ix.cmake.orig	2022-06-22 16:46:24.000000000 +0000
+++ cmake/config-ix.cmake
@@ -668,7 +668,7 @@ set(COMPILER_RT_SANITIZERS_TO_BUILD all 
 list_replace(COMPILER_RT_SANITIZERS_TO_BUILD all "${ALL_SANITIZERS}")
 
 if (SANITIZER_COMMON_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|NetBSD|Fuchsia|SunOS" OR
+    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|NetBSD|Fuchsia" OR
     (OS_NAME MATCHES "Windows" AND NOT CYGWIN AND
         (NOT MINGW OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))))
   set(COMPILER_RT_HAS_SANITIZER_COMMON TRUE)
@@ -688,7 +688,7 @@ else()
   set(COMPILER_RT_HAS_ASAN FALSE)
 endif()
 
-if (OS_NAME MATCHES "Linux|FreeBSD|Windows|NetBSD|SunOS")
+if (OS_NAME MATCHES "Linux|FreeBSD|Windows|NetBSD")
   set(COMPILER_RT_ASAN_HAS_STATIC_RUNTIME TRUE)
 else()
   set(COMPILER_RT_ASAN_HAS_STATIC_RUNTIME FALSE)
@@ -738,7 +738,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|Fuchsia|SunOS|NetBSD|AIX")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|Fuchsia|NetBSD|AIX")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -763,7 +763,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND UBSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD|Windows|Android|Fuchsia|SunOS")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD|Windows|Android|Fuchsia")
   set(COMPILER_RT_HAS_UBSAN TRUE)
 else()
   set(COMPILER_RT_HAS_UBSAN FALSE)
