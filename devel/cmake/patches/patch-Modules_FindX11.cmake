$NetBSD: patch-Modules_FindX11.cmake,v 1.6 2015/01/17 13:29:55 adam Exp $

Patch in pkgsrc paths for finding X.

--- Modules/FindX11.cmake.orig	2014-12-15 20:07:43.000000000 +0000
+++ Modules/FindX11.cmake
@@ -73,7 +73,8 @@ if (UNIX)
   set(CMAKE_REQUIRED_QUIET_SAVE ${CMAKE_REQUIRED_QUIET})
   set(CMAKE_REQUIRED_QUIET ${X11_FIND_QUIETLY})
   set(X11_INC_SEARCH_PATH
-    /usr/pkg/xorg/include
+    @LOCALBASE@/xorg/include
+    @X11BASE@/xorg/include
     /usr/X11R6/include
     /usr/X11R7/include
     /usr/include/X11
@@ -84,7 +85,8 @@ if (UNIX)
   )
 
   set(X11_LIB_SEARCH_PATH
-    /usr/pkg/xorg/lib
+    @LOCALBASE@/xorg/lib
+    @X11BASE@/xorg/lib
     /usr/X11R6/lib
     /usr/X11R7/lib
     /usr/openwin/lib
