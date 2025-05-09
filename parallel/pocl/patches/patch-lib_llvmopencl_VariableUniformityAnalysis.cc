$NetBSD: patch-lib_llvmopencl_VariableUniformityAnalysis.cc,v 1.1 2025/05/09 06:05:19 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/VariableUniformityAnalysis.cc.orig	2025-05-03 06:42:36.209606048 +0000
+++ lib/llvmopencl/VariableUniformityAnalysis.cc
@@ -339,8 +339,8 @@ bool VariableUniformityAnalysisResult::i
         CallInst *CallInstr = dyn_cast<CallInst>(user);
         Function *Callee = CallInstr->getCalledFunction();
         if (Callee != nullptr &&
-            (Callee->getName().startswith("llvm.lifetime.end") ||
-             Callee->getName().startswith("llvm.lifetime.start"))) {
+            (Callee->getName().starts_with("llvm.lifetime.end") ||
+             Callee->getName().starts_with("llvm.lifetime.start"))) {
 #ifdef DEBUG_UNIFORMITY_ANALYSIS
           std::cerr << "### alloca is used by llvm.lifetime" << std::endl;
           user->dump();
