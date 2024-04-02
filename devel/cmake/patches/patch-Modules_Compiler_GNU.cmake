$NetBSD: patch-Modules_Compiler_GNU.cmake,v 1.2 2024/04/02 17:27:41 adam Exp $

Add CMAKE_PKGSRC_BUILD_FLAGS to allow pkgsrc-based builds to set
compiler optimizer flags (overrides CMAKE_BUILD_TYPE).  Also enabled
for CMAKE_BOOTSTRAP so it is applied to the build of cmake itself.

--- Modules/Compiler/GNU.cmake.orig	2024-03-21 13:32:22.000000000 +0000
+++ Modules/Compiler/GNU.cmake
@@ -109,9 +109,11 @@ macro(__compiler_gnu lang)
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
