$NetBSD: patch-external_boringssl_util_android-cmake_android.toolchain.cmake,v 1.1 2025/08/21 16:36:51 ryoon Exp $

--- external/boringssl/util/android-cmake/android.toolchain.cmake.orig	2025-08-21 15:44:07.283321579 +0000
+++ external/boringssl/util/android-cmake/android.toolchain.cmake
@@ -184,7 +184,7 @@
 #
 # ------------------------------------------------------------------------------
 
-cmake_minimum_required( VERSION 2.6.3 )
+cmake_minimum_required( VERSION 3.5 )
 
 if( DEFINED CMAKE_CROSSCOMPILING )
  # subsequent toolchain loading is not really needed
