$NetBSD: patch-gcc_jit_libgccjit.h,v 1.2 2025/06/11 13:27:05 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/jit/libgccjit.h.orig	2025-05-23 11:02:04.752204777 +0000
+++ gcc/jit/libgccjit.h
@@ -21,6 +21,9 @@ along with GCC; see the file COPYING3.  
 #define LIBGCCJIT_H
 
 #include <stdio.h>
+#ifdef __APPLE__
+# include <sys/types.h>  /* For ssize_t.  */
+#endif
 
 #ifdef __cplusplus
 extern "C" {
