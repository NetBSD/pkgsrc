$NetBSD: patch-CompilerChecks.cmake,v 1.1 2026/09/14 22:10:50 wiz Exp $

Code is not ready for error.

--- CompilerChecks.cmake.orig	2024-06-10 07:43:42.000000000 +0000
+++ CompilerChecks.cmake
@@ -28,7 +28,7 @@ if (UNIX)
     add_c_compiler_flag("-Werror=strict-prototypes" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wwrite-strings" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Werror=write-strings" SUPPORTED_COMPILER_FLAGS)
-    add_c_compiler_flag("-Werror-implicit-function-declaration" SUPPORTED_COMPILER_FLAGS)
+    add_c_compiler_flag("-Wno-implicit-function-declaration" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wpointer-arith" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Werror=pointer-arith" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wdeclaration-after-statement" SUPPORTED_COMPILER_FLAGS)
