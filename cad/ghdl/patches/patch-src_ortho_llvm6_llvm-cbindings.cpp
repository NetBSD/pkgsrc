$NetBSD: patch-src_ortho_llvm6_llvm-cbindings.cpp,v 1.1 2022/12/22 16:23:28 wiz Exp $

llvm 15 support
https://github.com/ghdl/ghdl/commit/bc95c0710baaf539085879e5008361e3ecb04600

--- src/ortho/llvm6/llvm-cbindings.cpp.orig	2022-02-28 18:46:53.000000000 +0000
+++ src/ortho/llvm6/llvm-cbindings.cpp
@@ -41,6 +41,15 @@
 #define USE_DEBUG
 #endif
 
+#if LLVM_VERSION_MAJOR >= 15
+#define USE_OPAQUE_POINTERS
+#else
+#define LLVMBuildGEP2(B,T,P,I,Nu,Na) LLVMBuildGEP(B,P,I,Nu,Na)
+#define LLVMBuildLoad2(B,T,P,N) LLVMBuildLoad(B,P,N)
+#define LLVMBuildCall2(B,T,F,A,Nu,Na) LLVMBuildCall(B,F,A,Nu,Na)
+#define LLVMConstGEP2(T,V,I,N) LLVMConstGEP(V,I,N)
+#endif
+
 #ifdef USE_DEBUG
 #include "llvm/IR/IRBuilder.h"
 #include "llvm/IR/DIBuilder.h"
@@ -77,6 +86,7 @@ static LLVMBuilderRef ExtraBuilder;
 static LLVMValueRef StackSaveFun;
 static LLVMValueRef StackRestoreFun;
 static LLVMValueRef CopySignFun;
+static LLVMTypeRef CopySignFunType;
 
 static LLVMValueRef Fp0_5;
 
@@ -311,9 +321,9 @@ ortho_llvm_init(const char *Filename, un
 
   ParamTypes[0] = LLVMDoubleType();
   ParamTypes[1] = LLVMDoubleType();
+  CopySignFunType = LLVMFunctionType(LLVMDoubleType(), ParamTypes, 2, false);
   CopySignFun = LLVMAddFunction
-    (TheModule, "llvm.copysign.f64",
-     LLVMFunctionType(LLVMDoubleType(), ParamTypes, 2, false));
+     (TheModule, "llvm.copysign.f64", CopySignFunType);
 
   Fp0_5 = LLVMConstReal(LLVMDoubleType(), 0.5);
 
@@ -326,7 +336,7 @@ ortho_llvm_init(const char *Filename, un
 
   AttrId = LLVMGetEnumAttributeKindForName("uwtable", 7);
   assert (AttrId != 0);
-  UwtableAttr = LLVMCreateEnumAttribute(LLVMGetGlobalContext(), AttrId, 0);
+  UwtableAttr = LLVMCreateEnumAttribute(LLVMGetGlobalContext(), AttrId, 1);
 #endif
 
 #ifdef USE_DEBUG
@@ -602,11 +612,19 @@ struct OTnodeIncompleteAcc : OTnodeAccBa
 extern "C" OTnode
 new_access_type(OTnode DType)
 {
+  LLVMTypeRef Ptr;
+
+#ifdef USE_OPAQUE_POINTERS
+  Ptr = LLVMPointerTypeInContext(LLVMGetGlobalContext(), 0);
+#else
   if (DType == nullptr) {
     return new OTnodeIncompleteAcc();
-  } else {
-    return new OTnodeAcc(LLVMPointerType(DType->Ref, 0), DType);
   }
+
+  Ptr = LLVMPointerType(DType->Ref, 0);
+#endif
+
+  return new OTnodeAcc(Ptr, DType);
 }
 
 extern "C" void
@@ -615,8 +633,11 @@ finish_access_type(OTnodeAcc *AccType, O
   //  Must be incomplete.
   assert (AccType->Acc == nullptr);
 
+#ifndef USE_OPAQUE_POINTERS
   LLVMTypeRef Types[1] = { DType->Ref };
   LLVMStructSetBody(LLVMGetElementType(AccType->Ref), Types, 1, 0);
+#endif
+
   AccType->Acc = DType;
 #ifdef USE_DEBUG
   if (FlagDebug) {
@@ -740,7 +761,7 @@ finish_record_type(OElementList *Els, OT
   LLVMTypeRef *Types = new LLVMTypeRef[Els->BndCount];
 
   //  Create types array for elements.
-  int i = 0;
+  unsigned i = 0;
   bool Bounded = true;
   for (OFnodeBase *Field : *Els->Els) {
     if (Field->FType->Bounded)
@@ -1014,18 +1035,15 @@ new_type_decl(OIdent Ident, OTnode Atype
       break;
 
     case OTKIncompleteAccess:
-      if (static_cast<OTnodeAccBase*>(Atype)->Acc == nullptr) {
-        //  Still incomplete
+    case OTKAccess:
+      {
+        OTnode Ptr = static_cast<OTnodeAccBase*>(Atype)->Acc;
+        // Possibly still incomplete
         Atype->Dbg = DBuilder->createPointerType
-          (nullptr, Atype->getBitSize(), 0, None, StringRef(Ident.cstr));
+          (Ptr ? Ptr->Dbg : nullptr,
+           Atype->getBitSize(), 0, None, StringRef(Ident.cstr));
         break;
       }
-      // Fallthrough
-    case OTKAccess:
-      Atype->Dbg = DBuilder->createPointerType
-        (static_cast<OTnodeAcc*>(Atype)->Acc->Dbg,
-         Atype->getBitSize(), 0, None, StringRef(Ident.cstr));
-      break;
 
     case OTKArray:
       //  The debug info has already been created for arrays, as they can be
@@ -1432,13 +1450,14 @@ new_interface_decl(OInterList *Inters,
 struct ODnodeSubprg : ODnodeBase {
   // Interfaces
   std::vector<ODnodeInter *> Inters;
+  LLVMTypeRef Ftype;
   //  Storage
   OStorage Storage;
   OIdent Ident;
   ODKind getKind() const override { return ODKSubprg; }
-  ODnodeSubprg(LLVMValueRef R, OTnode T, OStorage S, OIdent Id,
+  ODnodeSubprg(LLVMValueRef R, OTnode T, LLVMTypeRef Ft, OStorage S, OIdent Id,
                const std::vector<ODnodeInter *> &Inters) :
-    ODnodeBase(R, T), Inters(Inters), Storage(S), Ident(Id) {}
+    ODnodeBase(R, T), Inters(Inters), Ftype(Ft), Storage(S), Ident(Id) {}
 };
 
 extern "C" void
@@ -1488,8 +1507,8 @@ finish_subprogram_decl(OInterList *Inter
 
   //  Create the result.
   ODnodeSubprg *R;
-  R = new ODnodeSubprg(Decl, Inters->Rtype, Inters->Storage, Inters->Ident,
-                       std::move(*Inters->Inters));
+  R = new ODnodeSubprg(Decl, Inters->Rtype, Ftype, Inters->Storage,
+                       Inters->Ident, std::move(*Inters->Inters));
   *Res = R;
 }
 
@@ -1693,8 +1712,8 @@ finish_declare_stmt ()
 
     if (CurrentDeclareBlock->StackValue != nullptr) {
       //  Restore stack pointer
-      LLVMBuildCall(Builder, StackRestoreFun,
-		    &CurrentDeclareBlock->StackValue, 1, "");
+      LLVMBuildCall2(Builder, LLVMVoidType(), StackRestoreFun,
+                     &CurrentDeclareBlock->StackValue, 1, "");
     }
     //  Execution will continue on the next statement
     LLVMBuildBr(Builder, Bb);
@@ -2084,8 +2103,8 @@ new_function_call (OAssocList *Assocs)
   LLVMValueRef Res;
 
   if (!Unreach) {
-    Res = LLVMBuildCall(Builder, Assocs->Subprg->Ref,
-			Assocs->Vals, Assocs->Subprg->Inters.size(), "");
+    Res = LLVMBuildCall2(Builder, Assocs->Subprg->Ftype, Assocs->Subprg->Ref,
+                         Assocs->Vals, Assocs->Subprg->Inters.size(), "");
   } else {
     Res = nullptr;
   }
@@ -2097,8 +2116,8 @@ extern "C" void
 new_procedure_call (OAssocList *Assocs)
 {
   if (!Unreach) {
-    LLVMBuildCall(Builder, Assocs->Subprg->Ref,
-		  Assocs->Vals, Assocs->Subprg->Inters.size(), "");
+    LLVMBuildCall2(Builder, Assocs->Subprg->Ftype, Assocs->Subprg->Ref,
+                   Assocs->Vals, Assocs->Subprg->Inters.size(), "");
   }
   delete Assocs->Vals;
 }
@@ -2468,7 +2487,7 @@ new_convert (OEnode Val, OTnode Rtype)
 	LLVMValueRef Args[2];
 	Args[0] = Fp0_5;
 	Args[1] = Val.Ref;
-	V = LLVMBuildCall(Builder, CopySignFun, Args, 2, "");
+	V = LLVMBuildCall2(Builder, CopySignFunType, CopySignFun, Args, 2, "");
 	V = LLVMBuildFAdd(Builder, V, Val.Ref, "");
 	Res = LLVMBuildFPToSI(Builder, V, Rtype->Ref, "");
       }
@@ -2528,8 +2547,12 @@ new_alloca (OTnode Rtype, OEnode Size)
 	LLVMPositionBuilderBefore(ExtraBuilder, FirstInsn);
 	Bld = ExtraBuilder;
       }
+#ifdef USE_OPAQUE_POINTERS
+      LLVMTypeRef Ptr = LLVMPointerTypeInContext(LLVMGetGlobalContext(), 0);
+#endif
+
       CurrentDeclareBlock->StackValue =
-	LLVMBuildCall(Bld, StackSaveFun, nullptr, 0, "");
+	LLVMBuildCall2(Bld, Ptr, StackSaveFun, nullptr, 0, "");
     }
     Res = LLVMBuildArrayAlloca(Builder, LLVMInt8Type(), Size.Ref, "");
     //  Convert
@@ -2564,10 +2587,10 @@ new_global_selected_element (OGnode Rec,
   case OF_Record:
     {
       LLVMValueRef Idx[2];
+      OFnodeRec *F = static_cast<OFnodeRec *>(El);
       Idx[0] = LLVMConstInt(LLVMInt32Type(), 0, 0);
-      Idx[1] = LLVMConstInt(LLVMInt32Type(),
-			    static_cast<OFnodeRec *>(El)->Index, 0);
-      Res = LLVMConstGEP(Rec.Ref, Idx, 2);
+      Idx[1] = LLVMConstInt(LLVMInt32Type(), F->Index, 0);
+      Res = LLVMConstGEP2(Rec.Gtype->Ref, Rec.Ref, Idx, 2);
     }
     break;
   case OF_Union:
@@ -2629,7 +2652,7 @@ new_value (OLnode *Lvalue)
     if (Lvalue->Direct)
       Res = Lvalue->Ref;
     else
-      Res = LLVMBuildLoad(Builder, Lvalue->Ref, "");
+      Res = LLVMBuildLoad2(Builder, Lvalue->Ltype->Ref, Lvalue->Ref, "");
   }
   return {Res, Lvalue->Ltype };
 }
@@ -2646,15 +2669,16 @@ new_indexed_element (OLnode *Arr, OEnode
 {
   LLVMValueRef Idx[2];
   LLVMValueRef Res;
+  OTnode ElType = static_cast<OTnodeArr *>(Arr->Ltype)->ElType;
 
   if (Unreach)
     Res = nullptr;
   else {
     Idx[0] = LLVMConstInt(LLVMInt32Type(), 0, 0);
     Idx[1] = Index.Ref;
-    Res = LLVMBuildGEP(Builder, Arr->Ref, Idx, 2, "");
+    Res = LLVMBuildGEP2(Builder, Arr->Ltype->Ref, Arr->Ref, Idx, 2, "");
   }
-  return { false, Res, static_cast<OTnodeArr *>(Arr->Ltype)->ElType };
+  return { false, Res, ElType };
 }
 
 extern "C" OLnode
@@ -2668,7 +2692,7 @@ new_slice (OLnode *Arr, OTnode Rtype, OE
   else {
     Idx[0] = LLVMConstInt(LLVMInt32Type(), 0, 0);
     Idx[1] = Index.Ref;
-    Res = LLVMBuildGEP(Builder, Arr->Ref, Idx, 2, "");
+    Res = LLVMBuildGEP2(Builder, Arr->Ltype->Ref, Arr->Ref, Idx, 2, "");
     Res = LLVMBuildBitCast(Builder, Res, LLVMPointerType(Rtype->Ref, 0), "");
   }
   return { false, Res, Rtype};
@@ -2686,10 +2710,10 @@ new_selected_element (OLnode *Rec, OFnod
     case OF_Record:
       {
 	LLVMValueRef Idx[2];
+        OFnodeRec *F = static_cast<OFnodeRec *>(El);
 	Idx[0] = LLVMConstInt(LLVMInt32Type(), 0, 0);
-	Idx[1] = LLVMConstInt(LLVMInt32Type(),
-			      static_cast<OFnodeRec *>(El)->Index, 0);
-	Res = LLVMBuildGEP(Builder, Rec->Ref, Idx, 2, "");
+	Idx[1] = LLVMConstInt(LLVMInt32Type(), F->Index, 0);
+	Res = LLVMBuildGEP2(Builder, Rec->Ltype->Ref, Rec->Ref, Idx, 2, "");
       }
       break;
     case OF_Union:
@@ -2705,6 +2729,7 @@ extern "C" OLnode
 new_access_element (OEnode Acc)
 {
   LLVMValueRef Res;
+  OTnode Ptype = static_cast<OTnodeAccBase *>(Acc.Etype)->Acc;
 
   switch(Acc.Etype->Kind) {
   case OTKAccess:
@@ -2717,13 +2742,13 @@ new_access_element (OEnode Acc)
 
       Idx[0] = LLVMConstInt(LLVMInt32Type(), 0, 0);
       Idx[1] = LLVMConstInt(LLVMInt32Type(), 0, 0);
-      Res = LLVMBuildGEP(Builder, Acc.Ref, Idx, 2, "");
+      Res = LLVMBuildGEP2(Builder, Acc.Etype->Ref, Acc.Ref, Idx, 2, "");
     }
     break;
   default:
     llvm_unreachable("bad new_access_element");
   }
-  return {false, Res, static_cast<OTnodeAccBase *>(Acc.Etype)->Acc };
+  return {false, Res, Ptype };
 }
 
 extern "C" OEnode
