$NetBSD: patch-src_boost.cmake,v 1.1 2025/10/08 12:13:08 adam Exp $

Don't look for boost_system library.

--- src/boost.cmake.orig	2025-10-08 11:21:12.510547411 +0000
+++ src/boost.cmake
@@ -6,7 +6,7 @@ else()
 endif()
 mark_as_advanced(VERA_USE_SYSTEM_BOOST)
 
-set(boostLibs filesystem system program_options regex wave)
+set(boostLibs filesystem program_options regex wave)
 if(VERA_PYTHON)
   list(APPEND boostLibs python)
 endif()
