$NetBSD: patch-ffi_targets.cpp,v 1.1 2022/01/12 21:13:50 wiz Exp $

Stopgap fix for llvm-12+
https://github.com/numba/llvmlite/pull/802/files

--- ffi/targets.cpp.orig	2021-08-20 18:17:31.365363100 +0000
+++ ffi/targets.cpp
@@ -232,7 +232,9 @@ LLVMPY_CreateTargetMachine(LLVMTargetRef
         rm = Reloc::DynamicNoPIC;
 
     TargetOptions opt;
+#if LLVM_VERSION_MAJOR < 12
     opt.PrintMachineCode = PrintMC;
+#endif
 
     bool jit = JIT;
 
