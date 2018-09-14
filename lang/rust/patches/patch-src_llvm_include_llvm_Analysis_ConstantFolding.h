$NetBSD: patch-src_llvm_include_llvm_Analysis_ConstantFolding.h,v 1.1 2018/09/14 10:04:43 jperkin Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- src/llvm/include/llvm/Analysis/ConstantFolding.h.orig	2018-08-01 16:32:37.000000000 +0000
+++ src/llvm/include/llvm/Analysis/ConstantFolding.h
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
