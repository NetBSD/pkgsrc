$NetBSD: patch-lib_llvmopencl_LLVMUtils.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/LLVMUtils.cc.orig	2024-06-18 12:15:45.000000000 +0000
+++ lib/llvmopencl/LLVMUtils.cc
@@ -37,7 +37,6 @@ IGNORE_COMPILER_WARNING("-Wunused-parame
 #include "AllocasToEntry.h"
 #include "AutomaticLocals.h"
 #include "BarrierTailReplication.h"
-#include "BreakConstantGEPs.h"
 #include "CanonicalizeBarriers.h"
 #include "DebugHelpers.h"
 #include "Flatten.hh"
@@ -250,7 +249,7 @@ isAutomaticLocal(llvm::Function *F, llvm
   std::string FuncName = F->getName().str();
   if (!llvm::isa<llvm::PointerType>(Var.getType()) || Var.isConstant())
     return false;
-  if (Var.getName().startswith(FuncName + ".")) {
+  if (Var.getName().starts_with(FuncName + ".")) {
     assert(isGVarUsedByFunction(&Var, F) == true);
     return true;
   }
@@ -421,7 +420,7 @@ bool isKernelToProcess(const llvm::Funct
     return false;
   if (!F.hasName())
     return false;
-  if (F.getName().startswith("@llvm"))
+  if (F.getName().starts_with("@llvm"))
     return false;

   NamedMDNode *kernels = m->getNamedMetadata("opencl.kernels");
@@ -456,7 +455,7 @@ void removeUnreachableSwitchCases(llvm::
   for (Function::iterator FI = F.begin(), FE = F.end(); FI != FE; ++FI) {
     BasicBlock *BB = &*FI;

-    if (BB->hasName() && BB->getName().startswith("default.unreachable")) {
+    if (BB->hasName() && BB->getName().starts_with("default.unreachable")) {
 #ifdef DEBUG_UNREACHABLE_SWITCH_REMOVAL
       std::cerr << "##################################################\n";
       std::cerr << "### converting unreachable block: " << (void *)BB << "\n";
@@ -578,7 +577,6 @@ void registerPassBuilderPasses(llvm::Pas
   AllocasToEntry::registerWithPB(PB);
   AutomaticLocals::registerWithPB(PB);
   BarrierTailReplication::registerWithPB(PB);
-  BreakConstantGEPs::registerWithPB(PB);
   CanonicalizeBarriers::registerWithPB(PB);
   FlattenAll::registerWithPB(PB);
   FlattenBarrierSubs::registerWithPB(PB);
