$NetBSD: patch-Modules_FindX11.cmake,v 1.7 2015/06/12 18:42:25 richard Exp $

Patch in pkgsrc paths for finding X.

--- Modules/FindX11.cmake.orig	2015-06-01 15:56:08.000000000 +0000
+++ Modules/FindX11.cmake
@@ -73,7 +73,7 @@ if (UNIX)
   set(CMAKE_REQUIRED_QUIET_SAVE ${CMAKE_REQUIRED_QUIET})
   set(CMAKE_REQUIRED_QUIET ${X11_FIND_QUIETLY})
   set(X11_INC_SEARCH_PATH
-    /usr/pkg/xorg/include
+    @X11BASE@/include
     /usr/X11R6/include
     /usr/X11R7/include
     /usr/include/X11
@@ -84,7 +84,7 @@ if (UNIX)
   )
 
   set(X11_LIB_SEARCH_PATH
-    /usr/pkg/xorg/lib
+    @X11BASE@/lib
     /usr/X11R6/lib
     /usr/X11R7/lib
     /usr/openwin/lib
