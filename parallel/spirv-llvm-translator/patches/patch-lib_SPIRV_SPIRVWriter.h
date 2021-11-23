$NetBSD: patch-lib_SPIRV_SPIRVWriter.h,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- lib/SPIRV/SPIRVWriter.h.orig	2021-10-15 21:15:19.000000000 +0000
+++ lib/SPIRV/SPIRVWriter.h
@@ -75,7 +75,8 @@ public:
   // a function, that is necessary for a convenient function pointers handling.
   // By default transValue uses 'Decl' mode, which means every function
   // we meet during the translation should result in its declaration generated.
-  // In 'Pointer' mode we generate OpConstFunctionPointerINTEL constant instead.
+  // In 'Pointer' mode we generate OpConstantFunctionPointerINTEL constant
+  // instead.
   enum class FuncTransMode { Decl, Pointer };
 
   SPIRVType *transType(Type *T);
