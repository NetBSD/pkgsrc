$NetBSD: patch-conf_FindLLVM.cmake,v 1.1 2019/07/09 16:33:30 nia Exp $

Look for pkgsrc llvm.

--- conf/FindLLVM.cmake.orig	2018-06-02 09:25:36.000000000 +0000
+++ conf/FindLLVM.cmake
@@ -42,14 +42,17 @@ if (LLVM_INCLUDE_DIR)
   set(LLVM_FOUND TRUE)
 else (LLVM_INCLUDE_DIR)
   file(GLOB LLVM_SEARCHPATHS /usr/lib/llvm*/bin)
-  find_program(LLVM_CONFIG_EXECUTABLE
-    NAMES llvm-config
-    PATHS
-    /opt/local/bin
-    /opt/llvm/2.7/bin
-    /opt/llvm/bin
-    ${LLVM_SEARCHPATHS}
-    )
+
+  if (NOT LLVM_CONFIG_EXECUTABLE)
+    find_program(LLVM_CONFIG_EXECUTABLE
+      NAMES llvm-config
+      PATHS
+      /opt/local/bin
+      /opt/llvm/2.7/bin
+      /opt/llvm/bin
+      ${LLVM_SEARCHPATHS}
+      )
+  endif (NOT LLVM_CONFIG_EXECUTABLE)
 
   find_program(LLVM_GCC_EXECUTABLE
     NAMES llvm-gcc llvmgcc
