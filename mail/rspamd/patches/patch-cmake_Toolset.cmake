$NetBSD: patch-cmake_Toolset.cmake,v 1.1 2020/05/18 11:10:56 nia Exp $

Avoid specifying a custom linker:
gcc: error: unrecognized command line option '-fuse-ld=lld'; did you mean '-fuse-ld=bfd'?

--- cmake/Toolset.cmake.orig	2020-04-01 13:57:55.000000000 +0000
+++ cmake/Toolset.cmake
@@ -41,8 +41,8 @@ endif ()
 
 option(LINKER_NAME "Linker name or full path")
 
-find_program(LLD_PATH NAMES "ld.lld" "lld")
-find_program(GOLD_PATH NAMES "ld.gold" "gold")
+#find_program(LLD_PATH NAMES "ld.lld" "lld")
+#find_program(GOLD_PATH NAMES "ld.gold" "gold")
 
 if(NOT LINKER_NAME)
     if(LLD_PATH)
