$NetBSD: patch-src_rustllvm_RustWrapper.cpp,v 1.1 2020/05/16 19:36:13 tnn Exp $

LLVM 10 compatibility

--- src/rustllvm/RustWrapper.cpp.orig	2020-04-20 22:17:56.000000000 +0000
+++ src/rustllvm/RustWrapper.cpp
@@ -1328,8 +1328,13 @@ extern "C" LLVMValueRef LLVMRustBuildMem
                                             LLVMValueRef Dst, unsigned DstAlign,
                                             LLVMValueRef Val,
                                             LLVMValueRef Size, bool IsVolatile) {
+#if LLVM_VERSION_GE(10, 0)
+  return wrap(unwrap(B)->CreateMemSet(
+      unwrap(Dst), unwrap(Val), unwrap(Size), MaybeAlign(DstAlign), IsVolatile));
+#else
   return wrap(unwrap(B)->CreateMemSet(
       unwrap(Dst), unwrap(Val), unwrap(Size), DstAlign, IsVolatile));
+#endif
 }
 
 extern "C" LLVMValueRef
