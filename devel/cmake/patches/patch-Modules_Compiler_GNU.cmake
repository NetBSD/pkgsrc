$NetBSD: patch-Modules_Compiler_GNU.cmake,v 1.1 2018/04/08 19:09:46 chuck Exp $

Add CMAKE_PKGSRC_BUILD_FLAGS to allow pkgsrc-based builds to set
compiler optimizer flags (overrides CMAKE_BUILD_TYPE).  Also enabled
for CMAKE_BOOTSTRAP so it is applied to the build of cmake itself.

--- Modules/Compiler/GNU.cmake.orig	2018-03-16 07:16:31.000000000 -0400
+++ Modules/Compiler/GNU.cmake	2018-04-07 16:23:51.000000000 -0400
@@ -39,9 +39,15 @@
   # Initial configuration flags.
   string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
   string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -g")
-  string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os -DNDEBUG")
-  string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3 -DNDEBUG")
-  string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g -DNDEBUG")
+  if(CMAKE_BOOTSTRAP OR CMAKE_PKGSRC_BUILD_FLAGS)
+    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -g -DNDEBUG")
+  else()
+    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Os -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -O3 -DNDEBUG")
+    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -O2 -g -DNDEBUG")
+  endif()
   set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E <SOURCE> > <PREPROCESSED_SOURCE>")
   set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -S <SOURCE> -o <ASSEMBLY_SOURCE>")
   if(NOT APPLE OR NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4) # work around #4462
