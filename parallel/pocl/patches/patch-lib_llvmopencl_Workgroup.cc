$NetBSD: patch-lib_llvmopencl_Workgroup.cc,v 1.1 2025/05/09 06:05:19 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/Workgroup.cc.orig	2025-05-03 06:43:51.271687868 +0000
+++ lib/llvmopencl/Workgroup.cc
@@ -249,7 +249,7 @@ bool WorkgroupImpl::runOnModule(Module &
     // linker's switch --wrap=symbol, where calls to the "symbol" are replaced
     // with "__wrap_symbol" at link time.  These functions may not be referenced
     // until final link and being deleted by LLVM optimizations before it.
-    if (!i->isDeclaration() && !i->getName().startswith("__wrap_"))
+    if (!i->isDeclaration() && !i->getName().starts_with("__wrap_"))
       i->setLinkage(Function::InternalLinkage);
   }

@@ -467,11 +467,11 @@ static bool callsPrintf(Function *F) {
         continue;
       Function *callee = CallInstr->getCalledFunction();

-      if (callee->getName().startswith("llvm."))
+      if (callee->getName().starts_with("llvm."))
         continue;
-      if (callee->getName().equals("_cl_printf"))
+      if (callee->getName() == "_cl_printf")
         return true;
-      if (callee->getName().equals("__pocl_printf"))
+      if (callee->getName() == "__pocl_printf")
         return true;
       if (callsPrintf(callee))
         return true;
@@ -568,7 +568,7 @@ static void replacePrintfCalls(Value *pb
       if (oldF == nullptr)
         continue;

-      if (oldF->getName().equals("_cl_printf")) {
+      if (oldF->getName() == "_cl_printf") {
         ops.clear();
         ops.push_back(pb);
         ops.push_back(pbp);
@@ -598,7 +598,7 @@ static void replacePrintfCalls(Value *pb
         replaceCIMap.insert(
             std::pair<CallInst *, CallInst *>(CallInstr, NewCI));
       } else {
-        if (!oldF->getName().startswith("llvm."))
+        if (!oldF->getName().starts_with("llvm."))
           callsToCheck.push_back(CallInstr);
       }
     }
