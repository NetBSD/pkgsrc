$NetBSD: patch-CompilerChecks.cmake,v 1.4 2025/01/07 05:56:17 pho Exp $

Fix build with option libgcrypt: src/libgcrypt/libgcrypt.c fails to compile
with -Werror=unused-variable.

--- CompilerChecks.cmake.orig	2025-01-07 05:51:07.479870562 +0000
+++ CompilerChecks.cmake
@@ -48,7 +48,6 @@ if (UNIX)
     add_c_compiler_flag("-Werror=implicit-int" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wint-conversion" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Werror=int-conversion" SUPPORTED_COMPILER_FLAGS)
-    add_c_compiler_flag("-Werror=unused-variable" SUPPORTED_COMPILER_FLAGS)
 
     check_c_compiler_flag("-Wformat" REQUIRED_FLAGS_WFORMAT)
     if (REQUIRED_FLAGS_WFORMAT)
