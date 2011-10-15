$NetBSD: patch-Modules_FindX11.cmake,v 1.2 2011/10/15 07:24:31 adam Exp $

--- Modules/FindX11.cmake.orig	2011-10-04 16:09:24.000000000 +0000
+++ Modules/FindX11.cmake
@@ -60,7 +60,8 @@ IF (UNIX)
   SET(CMAKE_FIND_FRAMEWORK_SAVE ${CMAKE_FIND_FRAMEWORK})
   SET(CMAKE_FIND_FRAMEWORK NEVER)
   SET(X11_INC_SEARCH_PATH
-    /usr/pkg/xorg/include
+    @LOCALBASE@/xorg/include
+    @X11BASE@/include
     /usr/X11R6/include
     /usr/X11R7/include
     /usr/include/X11
@@ -70,7 +71,8 @@ IF (UNIX)
   )
 
   SET(X11_LIB_SEARCH_PATH
-    /usr/pkg/xorg/lib
+    @LOCALBASE@/xorg/lib
+    @X11BASE@/lib
     /usr/X11R6/lib
     /usr/X11R7/lib
     /usr/openwin/lib
