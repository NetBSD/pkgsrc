$NetBSD: patch-lib_SPIRV_libSPIRV_SPIRVFunction.h,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/libSPIRV/SPIRVFunction.h.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/libSPIRV/SPIRVFunction.h
@@ -171,18 +171,18 @@ private:
 
 typedef SPIRVEntryOpCodeOnly<OpFunctionEnd> SPIRVFunctionEnd;
 
-class SPIRVConstFunctionPointerINTEL : public SPIRVValue {
-  const static Op OC = OpConstFunctionPointerINTEL;
+class SPIRVConstantFunctionPointerINTEL : public SPIRVValue {
+  const static Op OC = OpConstantFunctionPointerINTEL;
   const static SPIRVWord FixedWordCount = 4;
 
 public:
-  SPIRVConstFunctionPointerINTEL(SPIRVId TheId, SPIRVType *TheType,
-                                 SPIRVFunction *TheFunction, SPIRVModule *M)
+  SPIRVConstantFunctionPointerINTEL(SPIRVId TheId, SPIRVType *TheType,
+                                    SPIRVFunction *TheFunction, SPIRVModule *M)
       : SPIRVValue(M, FixedWordCount, OC, TheType, TheId),
         TheFunction(TheFunction->getId()) {
     validate();
   }
-  SPIRVConstFunctionPointerINTEL()
+  SPIRVConstantFunctionPointerINTEL()
       : SPIRVValue(OC), TheFunction(SPIRVID_INVALID) {}
   SPIRVFunction *getFunction() const { return get<SPIRVFunction>(TheFunction); }
   _SPIRV_DEF_ENCDEC3(Type, Id, TheFunction)
