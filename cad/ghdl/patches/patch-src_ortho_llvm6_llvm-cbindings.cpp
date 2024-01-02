$NetBSD: patch-src_ortho_llvm6_llvm-cbindings.cpp,v 1.3 2024/01/02 00:42:03 ryoon Exp $

* Support LLVM 16
  https://github.com/ghdl/ghdl/commit/776731910064cb6df03be19d788f7f13b2f7d2f1
* Support LLVM 17
  https://github.com/ghdl/ghdl/commit/36a2e24f85aa3174d37b3a121632ac0b28bf990a

--- src/ortho/llvm6/llvm-cbindings.cpp.orig	2023-03-08 06:40:01.000000000 +0000
+++ src/ortho/llvm6/llvm-cbindings.cpp
@@ -31,10 +31,18 @@
 #include "llvm-c/BitWriter.h"
 
 #include "llvm-c/Analysis.h"
-#include "llvm-c/Transforms/Scalar.h"
-#if LLVM_VERSION_MAJOR >= 7
+
+#if LLVM_VERSION_MAJOR < 17
+# include "llvm-c/Transforms/Scalar.h"
+# if LLVM_VERSION_MAJOR >= 7
 //  Not present in llvm-6, present in llvm-7
-#include "llvm-c/Transforms/Utils.h"
+#  include "llvm-c/Transforms/Utils.h"
+# endif
+#else
+# include "llvm/Passes/OptimizationLevel.h"
+# include "llvm/Analysis/LoopAnalysisManager.h"
+# include "llvm/Analysis/CGSCCPassManager.h"
+# include "llvm/Passes/PassBuilder.h"
 #endif
 
 #if LLVM_VERSION_MAJOR >= 6
@@ -77,7 +85,11 @@ static LLVMTargetRef TheTarget;
 static LLVMTargetMachineRef TheTargetMachine;
 static LLVMTargetDataRef TheTargetData;
 static LLVMRelocMode TheReloc = LLVMRelocDefault;
-static LLVMCodeGenOptLevel Optimization = LLVMCodeGenLevelDefault;
+static LLVMCodeGenOptLevel OptimizationCGLev = LLVMCodeGenLevelDefault;
+
+#if LLVM_VERSION_MAJOR >= 17
+static OptimizationLevel OptimizationLev = OptimizationLevel::O0;
+#endif
 
 static LLVMBuilderRef Builder;
 static LLVMBuilderRef DeclBuilder;
@@ -118,16 +130,28 @@ set_optimization_level (unsigned level)
 {
   switch(level) {
   case 0:
-    Optimization = LLVMCodeGenLevelNone;
+    OptimizationCGLev = LLVMCodeGenLevelNone;
+#if LLVM_VERSION_MAJOR >= 17
+    OptimizationLev = OptimizationLevel::O0;
+#endif
     break;
   case 1:
-    Optimization = LLVMCodeGenLevelLess;
+    OptimizationCGLev = LLVMCodeGenLevelLess;
+#if LLVM_VERSION_MAJOR >= 17
+    OptimizationLev = OptimizationLevel::O1;
+#endif
     break;
   case 2:
-    Optimization = LLVMCodeGenLevelDefault;
+    OptimizationCGLev = LLVMCodeGenLevelDefault;
+#if LLVM_VERSION_MAJOR >= 17
+    OptimizationLev = OptimizationLevel::O2;
+#endif
     break;
   default:
-    Optimization = LLVMCodeGenLevelAggressive;
+    OptimizationCGLev = LLVMCodeGenLevelAggressive;
+#if LLVM_VERSION_MAJOR >= 17
+    OptimizationLev = OptimizationLevel::O3;
+#endif
     break;
   }
 }
@@ -201,7 +225,34 @@ generateCommon()
     }
   }
 
-  if (Optimization > LLVMCodeGenLevelNone) {
+#if LLVM_VERSION_MAJOR >= 17
+  // Create the analysis managers.
+  LoopAnalysisManager LAM;
+  FunctionAnalysisManager FAM;
+  CGSCCAnalysisManager CGAM;
+  ModuleAnalysisManager MAM;
+
+  // Create the new pass manager builder.
+  // Take a look at the PassBuilder constructor parameters for more
+  // customization, e.g. specifying a TargetMachine or various debugging
+  // options.
+  PassBuilder PB;
+
+  // Register all the basic analyses with the managers.
+  PB.registerModuleAnalyses(MAM);
+  PB.registerCGSCCAnalyses(CGAM);
+  PB.registerFunctionAnalyses(FAM);
+  PB.registerLoopAnalyses(LAM);
+  PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
+
+  // Create the pass manager.
+  // This one corresponds to a typical -O2 optimization pipeline.
+  ModulePassManager MPM = PB.buildPerModuleDefaultPipeline(OptimizationLev);
+
+  // Optimize the IR!
+  MPM.run(*unwrap(TheModule), MAM);
+#else
+  if (OptimizationCGLev > LLVMCodeGenLevelNone) {
     LLVMPassManagerRef PassManager;
     PassManager = LLVMCreateFunctionPassManagerForModule (TheModule);
 
@@ -214,7 +265,9 @@ generateCommon()
       LLVMRunFunctionPassManager (PassManager, Func);
     }
   }
+#endif
 }
+
 extern "C" void
 generate_object(char *Filename)
 {
@@ -292,7 +345,7 @@ ortho_llvm_init(const char *Filename, un
 
   //  Create a target machine
   TheTargetMachine = LLVMCreateTargetMachine
-    (TheTarget, Triple, "", "", Optimization, TheReloc,
+    (TheTarget, Triple, "", "", OptimizationCGLev, TheReloc,
      LLVMCodeModelDefault);
 
 #if LLVM_VERSION_MAJOR < 4
@@ -353,7 +406,7 @@ ortho_llvm_init(const char *Filename, un
 					    StringRef(*DebugCurrentDirectory));
     DebugCurrentCU = DBuilder->createCompileUnit
       (llvm::dwarf::DW_LANG_C, DebugCurrentFile, StringRef("ortho-llvm"),
-       Optimization > LLVMCodeGenLevelNone, StringRef(), 0);
+       OptimizationCGLev > LLVMCodeGenLevelNone, StringRef(), 0);
 
     DebugCurrentScope = DebugCurrentCU;
   }
@@ -1040,8 +1093,13 @@ new_type_decl(OIdent Ident, OTnode Atype
         OTnode Ptr = static_cast<OTnodeAccBase*>(Atype)->Acc;
         // Possibly still incomplete
         Atype->Dbg = DBuilder->createPointerType
-          (Ptr ? Ptr->Dbg : nullptr,
-           Atype->getBitSize(), 0, None, StringRef(Ident.cstr));
+          (Ptr ? Ptr->Dbg : nullptr, Atype->getBitSize(), 0,
+#if LLVM_VERSION_MAJOR >= 16
+	   std::nullopt,
+#else
+	   None,
+#endif
+	   StringRef(Ident.cstr));
         break;
       }
 
