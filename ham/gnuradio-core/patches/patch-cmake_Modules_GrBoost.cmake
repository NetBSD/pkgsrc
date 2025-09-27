$NetBSD: patch-cmake_Modules_GrBoost.cmake,v 1.1 2025/09/27 07:10:58 adam Exp $

Do not look for boost_system library.

--- cmake/Modules/GrBoost.cmake.orig	2025-09-24 16:01:37.086210515 +0000
+++ cmake/Modules/GrBoost.cmake
@@ -14,7 +14,7 @@ set(__INCLUDED_GR_BOOST_CMAKE TRUE)
 # Setup Boost and handle some system specific things
 ########################################################################
 
-set(BOOST_REQUIRED_COMPONENTS date_time program_options system regex thread)
+set(BOOST_REQUIRED_COMPONENTS date_time program_options regex thread)
 
 if(UNIX
    AND NOT BOOST_ROOT
