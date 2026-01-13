$NetBSD: patch-src_llvm-project_llvm_include_llvm_Analysis_ConstantFolding.h,v 1.11 2026/01/13 20:48:23 wiz Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h.orig	2025-10-28 16:34:16.000000000 +0000
+++ src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h
@@ -20,6 +20,11 @@
 #define LLVM_ANALYSIS_CONSTANTFOLDING_H
 
 #include "llvm/Support/Compiler.h"
+
+#ifdef __sun
+#undef CS
+#endif
+
 #include <stdint.h>
 
 namespace llvm {
