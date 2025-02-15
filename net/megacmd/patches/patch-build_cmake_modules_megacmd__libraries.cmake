$NetBSD: patch-build_cmake_modules_megacmd__libraries.cmake,v 1.1 2025/02/15 07:40:13 wiz Exp $

* Fix used pcre library name

--- build/cmake/modules/megacmd_libraries.cmake.orig	2025-01-30 14:04:12.000000000 +0100
+++ build/cmake/modules/megacmd_libraries.cmake
@@ -16,7 +16,7 @@ macro(load_megacmdserver_libraries)
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
         if(USE_PCRE) #TODO: UNTESTED!
-            pkg_check_modules(pcre REQUIRED IMPORTED_TARGET libpcre)
+            pkg_check_modules(pcre REQUIRED IMPORTED_TARGET libpcrecpp)
             target_link_libraries(LMegacmdServer PRIVATE PkgConfig::pcre)
             set(USE_PCRE 1)
         endif()
