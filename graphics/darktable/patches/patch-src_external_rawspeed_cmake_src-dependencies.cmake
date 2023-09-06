$NetBSD: patch-src_external_rawspeed_cmake_src-dependencies.cmake,v 1.1 2023/09/06 21:04:20 nia Exp $

Remove overly strict version requirements.

In particular, NetBSD 9 ships zlib 1.2.10. As far as I can tell, there
aren't any notable API changes between 1.2.10 and 1.2.11.

--- src/external/rawspeed/cmake/src-dependencies.cmake.orig	2023-06-12 21:39:40.000000000 +0000
+++ src/external/rawspeed/cmake/src-dependencies.cmake
@@ -33,7 +33,7 @@ if(WITH_OPENMP)
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OPENMP_VERSION_SPECIFIER}")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPENMP_VERSION_SPECIFIER}")
 
-  find_package(OpenMP 4.5)
+  find_package(OpenMP)
 
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_SAVE}")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_SAVE}")
@@ -81,7 +81,7 @@ unset(HAVE_PUGIXML)
 if(WITH_PUGIXML)
   message(STATUS "Looking for pugixml")
   if(NOT USE_BUNDLED_PUGIXML)
-    find_package(Pugixml 1.8)
+    find_package(Pugixml)
     if(NOT Pugixml_FOUND)
       message(SEND_ERROR "Did not find Pugixml! Either make it find Pugixml, or pass -DUSE_BUNDLED_PUGIXML=ON to enable in-tree pugixml.")
     else()
@@ -151,7 +151,7 @@ unset(HAVE_ZLIB)
 if (WITH_ZLIB)
   message(STATUS "Looking for ZLIB")
   if(NOT USE_BUNDLED_ZLIB)
-    find_package(ZLIB 1.2.11)
+    find_package(ZLIB)
     if(NOT ZLIB_FOUND)
       message(SEND_ERROR "Did not find ZLIB! Either make it find ZLIB, or pass -DWITH_ZLIB=OFF to disable ZLIB, or pass -DUSE_BUNDLED_ZLIB=ON to enable in-tree ZLIB.")
     else()
