$NetBSD: patch-src_llvm-project_llvm_include_llvm_Analysis_ConstantFolding.h,v 1.1 2019/04/14 12:42:03 he Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h.orig	2018-08-01 16:32:37.000000000 +0000
+++ src/llvm-project/llvm/include/llvm/Analysis/ConstantFolding.h
@@ -20,6 +20,10 @@
 #ifndef LLVM_ANALYSIS_CONSTANTFOLDING_H
 #define LLVM_ANALYSIS_CONSTANTFOLDING_H
 
+#ifdef __sun
+#undef CS
+#endif
+
 namespace llvm {
 class APInt;
 template <typename T> class ArrayRef;
