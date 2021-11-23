$NetBSD: patch-lib_SPIRV_libSPIRV_SPIRVOpCodeEnum.h,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/libSPIRV/SPIRVOpCodeEnum.h.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/libSPIRV/SPIRVOpCodeEnum.h
@@ -344,7 +344,7 @@ _SPIRV_OP(SubgroupImageBlockReadINTEL, 5
 _SPIRV_OP(SubgroupImageBlockWriteINTEL, 5578)
 _SPIRV_OP(SubgroupImageMediaBlockReadINTEL, 5580)
 _SPIRV_OP(SubgroupImageMediaBlockWriteINTEL, 5581)
-_SPIRV_OP(ConstFunctionPointerINTEL, 5600)
+_SPIRV_OP(ConstantFunctionPointerINTEL, 5600)
 _SPIRV_OP(FunctionPointerCallINTEL, 5601)
 _SPIRV_OP(AsmTargetINTEL, 5609)
 _SPIRV_OP(AsmINTEL, 5610)
