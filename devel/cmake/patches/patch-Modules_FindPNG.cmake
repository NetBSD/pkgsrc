$NetBSD: patch-Modules_FindPNG.cmake,v 1.1 2013/02/16 11:40:37 wiz Exp $

Support png-1.6.

--- Modules/FindPNG.cmake.orig	2012-10-31 15:32:05.000000000 +0000
+++ Modules/FindPNG.cmake
@@ -38,7 +38,7 @@ if(ZLIB_FOUND)
   /usr/local/include/libpng             # OpenBSD
   )
 
-  set(PNG_NAMES ${PNG_NAMES} png libpng png15 libpng15 png15d libpng15d png14 libpng14 png14d libpng14d png12 libpng12 png12d libpng12d)
+  set(PNG_NAMES ${PNG_NAMES} png libpng png16 libpng16 png15 libpng15 png15d libpng15d png14 libpng14 png14d libpng14d png12 libpng12 png12d libpng12d)
   find_library(PNG_LIBRARY NAMES ${PNG_NAMES} )
 
   if (PNG_LIBRARY AND PNG_PNG_INCLUDE_DIR)
