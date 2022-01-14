$NetBSD: patch-ffi_targets.cpp,v 1.2 2022/01/14 19:49:10 adam Exp $

Stopgap fix for llvm-12+
https://github.com/numba/llvmlite/pull/802/files

--- ffi/targets.cpp.orig	2022-01-14 14:39:38.000000000 +0000
+++ ffi/targets.cpp
@@ -233,7 +233,9 @@ LLVMPY_CreateTargetMachine(LLVMTargetRef
         rm = Reloc::DynamicNoPIC;
 
     TargetOptions opt;
+#if LLVM_VERSION_MAJOR < 12
     opt.PrintMachineCode = PrintMC;
+#endif
     opt.MCOptions.ABIName = ABIName;
 
     bool jit = JIT;
