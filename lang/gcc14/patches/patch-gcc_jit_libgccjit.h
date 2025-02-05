$NetBSD: patch-gcc_jit_libgccjit.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/jit/libgccjit.h
+++ gcc/jit/libgccjit.h
@@ -21,6 +21,9 @@ along with GCC; see the file COPYING3.  If not see
 #define LIBGCCJIT_H

 #include <stdio.h>
+#ifdef __APPLE__
+# include <sys/types.h>  /* For ssize_t.  */
+#endif

 #ifdef __cplusplus
 extern "C" {
