$NetBSD: patch-Modules_Compiler_GNU.cmake,v 1.1 2025/10/02 11:49:44 nia Exp $

Add CMAKE_PKGSRC_BUILD_FLAGS to allow pkgsrc-based builds to set
compiler optimizer flags (overrides CMAKE_BUILD_TYPE).  Also enabled
for CMAKE_BOOTSTRAP so it is applied to the build of cmake itself.

--- Modules/Compiler/GNU.cmake.orig	2017-11-10 12:28:57.000000000 +0000
+++ Modules/Compiler/GNU.cmake
@@ -39,9 +39,11 @@ macro(__compiler_gnu lang)
   # Initial configuration flags.
   string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
   string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -g")
-  string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os -DNDEBUG")
-  string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3 -DNDEBUG")
-  string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g -DNDEBUG")
+  if(NOT CMAKE_BOOTSTRAP AND NOT CMAKE_PKGSRC_BUILD_FLAGS)
+    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3 -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g -DNDEBUG")
+  endif()
   set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E <SOURCE> > <PREPROCESSED_SOURCE>")
   set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -S <SOURCE> -o <ASSEMBLY_SOURCE>")
   if(NOT APPLE OR NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4) # work around #4462
