$NetBSD: patch-lib_llvmopencl_OptimizeWorkItemFuncCalls.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/OptimizeWorkItemFuncCalls.cc.orig	2025-05-03 06:41:48.048591095 +0000
+++ lib/llvmopencl/OptimizeWorkItemFuncCalls.cc
@@ -52,13 +52,13 @@ static bool optimizeWorkItemFuncCalls(Fu
   // Let's avoid reoptimizing pocl_printf in the kernel compiler. It should
   // be optimized already in the bitcode library, and we do not want to
   // aggressively inline it to the kernel, causing compile time expansion.
-  if (F.getName().startswith("__pocl_print") &&
+  if (F.getName().starts_with("__pocl_print") &&
       !F.hasFnAttribute(Attribute::OptimizeNone)) {
     F.addFnAttr(Attribute::OptimizeNone);
     F.addFnAttr(Attribute::NoInline);
   }

-  if (F.getName().startswith("_") || F.hasFnAttribute(Attribute::OptimizeNone))
+  if (F.getName().starts_with("_") || F.hasFnAttribute(Attribute::OptimizeNone))
     return false;

   // Find calls to WI functions and unify them to a single call in the
