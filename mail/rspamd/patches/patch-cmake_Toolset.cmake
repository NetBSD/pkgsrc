$NetBSD: patch-cmake_Toolset.cmake,v 1.2 2021/12/21 15:00:41 triaxx Exp $

Avoid specifying a custom linker:
gcc: error: unrecognized command line option '-fuse-ld=lld'; did you mean '-fuse-ld=bfd'?

--- cmake/Toolset.cmake.orig	2021-11-01 14:33:30.000000000 +0000
+++ cmake/Toolset.cmake
@@ -52,8 +52,8 @@ endif ()
 
 option(LINKER_NAME "Linker name or full path")
 
-find_program(LLD_PATH NAMES "ld.lld" "lld")
-find_program(GOLD_PATH NAMES "ld.gold" "gold")
+#find_program(LLD_PATH NAMES "ld.lld" "lld")
+#find_program(GOLD_PATH NAMES "ld.gold" "gold")
 
 if(NOT LINKER_NAME)
     if(LLD_PATH)
