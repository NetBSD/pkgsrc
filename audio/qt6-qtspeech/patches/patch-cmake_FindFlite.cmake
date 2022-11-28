$NetBSD: patch-cmake_FindFlite.cmake,v 1.1 2022/11/28 13:44:14 nros Exp $

* pkgsrc flite does not use ALSA,
  the test will fail if pkgsrc alsa is
  installed and cmake finds it, this
  causes the flite feature to not be
  used in the package leading to PLIST
  breakage etc.

--- cmake/FindFlite.cmake.orig	2022-10-05 14:32:21.272294992 +0000
+++ cmake/FindFlite.cmake
@@ -25,6 +25,7 @@ include(CheckCXXSourceCompiles)
 # Flite can be built with ALSA support,
 # in which case we need to link ALSA as well
 find_package(ALSA QUIET)
+set(ALSA_FOUND 0)
 
 cmake_push_check_state(RESET)
 
