$NetBSD: patch-src_rustllvm_PassWrapper.cpp,v 1.1 2020/05/16 19:36:13 tnn Exp $

LLVM 10 compatibility

--- src/rustllvm/PassWrapper.cpp.orig	2020-04-20 22:17:56.000000000 +0000
+++ src/rustllvm/PassWrapper.cpp
@@ -67,7 +67,7 @@ extern "C" void LLVMInitializePasses() {
 }
 
 extern "C" void LLVMTimeTraceProfilerInitialize() {
-#if LLVM_VERSION_GE(9, 0)
+#if LLVM_VERSION_GE(9, 0) && LLVM_VERSION_LT(10, 0)
   timeTraceProfilerInitialize();
 #endif
 }
