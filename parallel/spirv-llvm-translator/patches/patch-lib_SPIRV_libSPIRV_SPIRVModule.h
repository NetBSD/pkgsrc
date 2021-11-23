$NetBSD: patch-lib_SPIRV_libSPIRV_SPIRVModule.h,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/libSPIRV/SPIRVModule.h.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/libSPIRV/SPIRVModule.h
@@ -263,8 +263,8 @@ public:
                            const std::vector<SPIRVValue *> &Elements) = 0;
   virtual SPIRVEntry *
   addSpecConstantCompositeContinuedINTEL(const std::vector<SPIRVValue *> &) = 0;
-  virtual SPIRVValue *addConstFunctionPointerINTEL(SPIRVType *Ty,
-                                                   SPIRVFunction *F) = 0;
+  virtual SPIRVValue *addConstantFunctionPointerINTEL(SPIRVType *Ty,
+                                                      SPIRVFunction *F) = 0;
   virtual SPIRVValue *addConstant(SPIRVValue *) = 0;
   virtual SPIRVValue *addConstant(SPIRVType *, uint64_t) = 0;
   virtual SPIRVValue *addConstant(SPIRVType *, llvm::APInt) = 0;
