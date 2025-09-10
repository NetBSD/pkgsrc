$NetBSD: patch-Modules_Compiler_GNU.cmake,v 1.3 2025/09/10 14:40:02 jperkin Exp $

Add CMAKE_PKGSRC_BUILD_FLAGS to allow pkgsrc-based builds to set
compiler optimizer flags (overrides CMAKE_BUILD_TYPE).  Also enabled
for CMAKE_BOOTSTRAP so it is applied to the build of cmake itself.

GCC on SunOS does not (yet) support LTO with the native linker.

--- Modules/Compiler/GNU.cmake.orig	2025-08-27 16:33:28.000000000 +0000
+++ Modules/Compiler/GNU.cmake
@@ -57,9 +57,11 @@ macro(__compiler_gnu lang)
   # Initial configuration flags.
   string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
   string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -g")
-  string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os")
-  string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3")
-  string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g")
+  if(NOT CMAKE_BOOTSTRAP AND NOT CMAKE_PKGSRC_BUILD_FLAGS)
+    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os")
+    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3")
+    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g")
+  endif()
   if(NOT "x${lang}" STREQUAL "xFortran")
     string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -DNDEBUG")
     string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -DNDEBUG")
@@ -99,7 +101,7 @@ macro(__compiler_gnu lang)
       list(APPEND __lto_flags -flto)
     endif()
 
-    if(NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4.7 AND NOT APPLE)
+    if(NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4.7 AND NOT APPLE AND NOT CMAKE_SYSTEM_NAME STREQUAL "SunOS")
       # '-ffat-lto-objects' introduced since GCC 4.7:
       # * https://gcc.gnu.org/onlinedocs/gcc-4.6.4/gcc/Option-Summary.html (no)
       # * https://gcc.gnu.org/onlinedocs/gcc-4.7.4/gcc/Option-Summary.html (yes)
