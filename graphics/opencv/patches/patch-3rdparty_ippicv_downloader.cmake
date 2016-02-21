$NetBSD: patch-3rdparty_ippicv_downloader.cmake,v 1.2 2016/02/21 14:10:46 fhajny Exp $

--- 3rdparty/ippicv/downloader.cmake.orig	2015-12-18 15:02:16.000000000 +0000
+++ 3rdparty/ippicv/downloader.cmake
@@ -6,6 +6,7 @@
 #
 
 function(_icv_downloader)
+  return()
   # Commit SHA in the opencv_3rdparty repo
   set(IPPICV_BINARIES_COMMIT "81a676001ca8075ada498583e4166079e5744668")
   # Define actual ICV versions
