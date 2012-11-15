$NetBSD: patch-Modules_FindX11.cmake,v 1.5 2012/11/15 19:31:55 adam Exp $

Patch in pkgsrc paths for finding X.

--- Modules/FindX11.cmake.orig	2012-10-31 15:32:05.000000000 +0000
+++ Modules/FindX11.cmake
@@ -61,7 +61,8 @@ if (UNIX)
   set(CMAKE_FIND_FRAMEWORK_SAVE ${CMAKE_FIND_FRAMEWORK})
   set(CMAKE_FIND_FRAMEWORK NEVER)
   set(X11_INC_SEARCH_PATH
-    /usr/pkg/xorg/include
+    @LOCALBASE@/xorg/include
+    @X11BASE@/xorg/include
     /usr/X11R6/include
     /usr/X11R7/include
     /usr/include/X11
@@ -71,7 +72,8 @@ if (UNIX)
   )
 
   set(X11_LIB_SEARCH_PATH
-    /usr/pkg/xorg/lib
+    @LOCALBASE@/xorg/lib
+    @X11BASE@/xorg/lib
     /usr/X11R6/lib
     /usr/X11R7/lib
     /usr/openwin/lib
