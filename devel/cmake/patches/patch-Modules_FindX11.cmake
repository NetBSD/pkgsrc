$NetBSD: patch-Modules_FindX11.cmake,v 1.1 2011/09/14 17:54:48 brook Exp $

--- Modules/FindX11.cmake.orig	2011-07-08 12:21:44.000000000 +0000
+++ Modules/FindX11.cmake
@@ -56,7 +56,8 @@ IF (UNIX)
   SET(CMAKE_FIND_FRAMEWORK_SAVE ${CMAKE_FIND_FRAMEWORK})
   SET(CMAKE_FIND_FRAMEWORK NEVER)
   SET(X11_INC_SEARCH_PATH
-    /usr/pkg/xorg/include
+    @LOCALBASE@/xorg/include
+    @X11BASE@/include
     /usr/X11R6/include 
     /usr/X11R7/include 
     /usr/include/X11
@@ -66,7 +67,8 @@ IF (UNIX)
   )
 
   SET(X11_LIB_SEARCH_PATH
-    /usr/pkg/xorg/lib
+    @LOCALBASE@/xorg/lib
+    @X11BASE@/lib
     /usr/X11R6/lib
     /usr/X11R7/lib
     /usr/openwin/lib 
