$NetBSD: patch-3rdparty_ippicv_ippicv.cmake,v 1.1 2017/09/04 15:23:49 fhajny Exp $

Do not download at build time.

--- 3rdparty/ippicv/ippicv.cmake.orig	2017-08-03 23:58:23.000000000 +0000
+++ 3rdparty/ippicv/ippicv.cmake
@@ -1,4 +1,5 @@
 function(download_ippicv root_var)
+  return()
   set(${root_var} "" PARENT_SCOPE)
 
   # Commit SHA in the opencv_3rdparty repo
