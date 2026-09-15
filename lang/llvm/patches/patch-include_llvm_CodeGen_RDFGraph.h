$NetBSD: patch-include_llvm_CodeGen_RDFGraph.h,v 1.1 2026/09/15 21:10:06 tnn Exp $

https://github.com/llvm/llvm-project/commit/a558d656043734cc4d02e0a0a12e4c308c28f8c7.patch

--- include/llvm/CodeGen/RDFGraph.h.orig	2025-12-12 10:35:47.000000000 +0000
+++ include/llvm/CodeGen/RDFGraph.h
@@ -447,7 +447,7 @@ private:
   AllocatorTy MemPool;
 };
 
-using RegisterSet = std::set<RegisterRef>;
+using RegisterSet = std::set<RegisterRef, RegisterRefLess>;
 
 struct TargetOperandInfo {
   TargetOperandInfo(const TargetInstrInfo &tii) : TII(tii) {}
