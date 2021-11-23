$NetBSD: patch-lib_SPIRV_SPIRVWriter.cpp,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/SPIRVWriter.cpp.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/SPIRVWriter.cpp
@@ -1418,7 +1418,7 @@ LLVMToSPIRVBase::transValueWithoutDecora
     if (!BM->checkExtension(ExtensionID::SPV_INTEL_function_pointers,
                             SPIRVEC_FunctionPointers, toString(V)))
       return nullptr;
-    return BM->addConstFunctionPointerINTEL(
+    return BM->addConstantFunctionPointerINTEL(
         transType(F->getType()),
         static_cast<SPIRVFunction *>(transValue(F, nullptr)));
   }
