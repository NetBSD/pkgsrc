$NetBSD: patch-lib_SPIRV_libSPIRV_SPIRVModule.cpp,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/libSPIRV/SPIRVModule.cpp.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/libSPIRV/SPIRVModule.cpp
@@ -269,8 +269,8 @@ public:
                            const std::vector<SPIRVValue *> &Elements) override;
   SPIRVEntry *addSpecConstantCompositeContinuedINTEL(
       const std::vector<SPIRVValue *> &) override;
-  SPIRVValue *addConstFunctionPointerINTEL(SPIRVType *Ty,
-                                           SPIRVFunction *F) override;
+  SPIRVValue *addConstantFunctionPointerINTEL(SPIRVType *Ty,
+                                              SPIRVFunction *F) override;
   SPIRVValue *addConstant(SPIRVValue *) override;
   SPIRVValue *addConstant(SPIRVType *, uint64_t) override;
   SPIRVValue *addConstant(SPIRVType *, llvm::APInt) override;
@@ -1142,9 +1142,10 @@ SPIRVEntry *SPIRVModuleImpl::addSpecCons
   return add(new SPIRVSpecConstantCompositeContinuedINTEL(this, Elements));
 }
 
-SPIRVValue *SPIRVModuleImpl::addConstFunctionPointerINTEL(SPIRVType *Ty,
-                                                          SPIRVFunction *F) {
-  return addConstant(new SPIRVConstFunctionPointerINTEL(getId(), Ty, F, this));
+SPIRVValue *SPIRVModuleImpl::addConstantFunctionPointerINTEL(SPIRVType *Ty,
+                                                             SPIRVFunction *F) {
+  return addConstant(
+      new SPIRVConstantFunctionPointerINTEL(getId(), Ty, F, this));
 }
 
 SPIRVValue *SPIRVModuleImpl::addUndef(SPIRVType *TheType) {
