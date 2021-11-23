$NetBSD: patch-lib_SPIRV_SPIRVReader.cpp,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/SPIRVReader.cpp.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/SPIRVReader.cpp
@@ -1452,9 +1452,9 @@ Value *SPIRVToLLVM::transValueWithoutDec
     return mapValue(BV, transValue(BI, nullptr, nullptr, false));
   }
 
-  case OpConstFunctionPointerINTEL: {
-    SPIRVConstFunctionPointerINTEL *BC =
-        static_cast<SPIRVConstFunctionPointerINTEL *>(BV);
+  case OpConstantFunctionPointerINTEL: {
+    SPIRVConstantFunctionPointerINTEL *BC =
+        static_cast<SPIRVConstantFunctionPointerINTEL *>(BV);
     SPIRVFunction *F = BC->getFunction();
     BV->setName(F->getName());
     return mapValue(BV, transFunction(F));
