$NetBSD: patch-lib_SPIRV_libSPIRV_SPIRVOpCode.h,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/libSPIRV/SPIRVOpCode.h.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/libSPIRV/SPIRVOpCode.h
@@ -226,7 +226,7 @@ inline bool isSpecConstantOpCode(Op OpCo
 inline bool isConstantOpCode(Op OpCode) {
   unsigned OC = OpCode;
   return (OpConstantTrue <= OC && OC <= OpSpecConstantOp) || OC == OpUndef ||
-         OC == OpConstantPipeStorage || OC == OpConstFunctionPointerINTEL;
+         OC == OpConstantPipeStorage || OC == OpConstantFunctionPointerINTEL;
 }
 
 inline bool isModuleScopeAllowedOpCode(Op OpCode) {
