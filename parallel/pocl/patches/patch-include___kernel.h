$NetBSD: patch-include___kernel.h,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- include/_kernel.h.orig	2025-05-03 06:04:20.489478228 +0000
+++ include/_kernel.h
@@ -143,6 +143,11 @@
 #undef LLVM_18_0
 #define LLVM_18_0
 
+#elif (__clang_major__ == 19)
+
+#undef LLVM_19_0
+#define LLVM_19_0
+
 #else
 
 #error Unsupported Clang/LLVM version.
