$NetBSD: patch-src_llvm-project_llvm_include_llvm_Analysis_ConstantFolding.h,v 1.2 2021/04/19 17:08:09 he Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h.orig	2020-12-08 20:04:43.000000000 +0000
+++ src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h
@@ -19,6 +19,10 @@
 #ifndef LLVM_ANALYSIS_CONSTANTFOLDING_H
 #define LLVM_ANALYSIS_CONSTANTFOLDING_H
 
+#ifdef __sun
+#undef CS
+#endif
+
 namespace llvm {
 class APInt;
 template <typename T> class ArrayRef;
