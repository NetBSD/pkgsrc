$NetBSD: patch-cmake_bsd.cmake,v 1.1 2019/10/23 00:21:26 fox Exp $

Support building with SDL2 instead of SDL.

--- cmake/bsd.cmake.orig	2019-09-24 11:04:39.000000000 +0000
+++ cmake/bsd.cmake
@@ -4,12 +4,12 @@ set(lib_base ${BSD_PREFIX_PATH}/include)
 
 set(BOOST_INCLUDEDIR ${lib_base})
 
-set(sdl_root ${lib_base}/SDL)
+set(sdl_root ${lib_base}/SDL2)
 
 include_directories("${sdl_root}")
 
 link_libraries(cannonball
-    SDL
+    SDL2
 )
 
 # Linking
@@ -17,7 +17,12 @@ link_directories(
     "${BSD_PREFIX_PATH}/lib"
 )
 
+add_definitions(-O3 -DSDL2)
+
 # Location for Cannonball to create save files
 # Used to auto-generate setup.hpp with various file paths
 set(xml_directory ./)
-set(sdl_flags "SDL_DOUBLEBUF | SDL_SWSURFACE")
+set(sdl_flags "SDL_WINDOW_RESIZABLE")
+
+# Set SDL2 instead of SDL1
+set(SDL2 1)
