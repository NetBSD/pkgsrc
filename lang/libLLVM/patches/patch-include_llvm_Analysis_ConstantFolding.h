$NetBSD: patch-include_llvm_Analysis_ConstantFolding.h,v 1.1 2019/01/26 21:17:20 tnn Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/Analysis/ConstantFolding.h.orig	2018-05-01 15:54:18.000000000 +0000
+++ include/llvm/Analysis/ConstantFolding.h
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
