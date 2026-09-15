$NetBSD: patch-include_llvm_CodeGen_RDFRegisters.h,v 1.1 2026/09/15 21:10:06 tnn Exp $

https://github.com/llvm/llvm-project/commit/a558d656043734cc4d02e0a0a12e4c308c28f8c7.patch

--- include/llvm/CodeGen/RDFRegisters.h.orig	2025-12-12 10:35:47.000000000 +0000
+++ include/llvm/CodeGen/RDFRegisters.h
@@ -199,6 +199,33 @@ private:
   std::vector<AliasInfo> AliasInfos;
 };
 
+struct RegisterRefEqualTo {
+  constexpr RegisterRefEqualTo(const llvm::rdf::PhysicalRegisterInfo &pri)
+      : PRI(&pri) {}
+
+  bool operator()(llvm::rdf::RegisterRef A, llvm::rdf::RegisterRef B) const {
+    return PRI->equal_to(A, B);
+  }
+
+private:
+  // Make it a pointer just in case. See comment in `RegisterRefLess` below.
+  const llvm::rdf::PhysicalRegisterInfo *PRI;
+};
+
+struct RegisterRefLess {
+  constexpr RegisterRefLess(const llvm::rdf::PhysicalRegisterInfo &pri)
+      : PRI(&pri) {}
+
+  bool operator()(llvm::rdf::RegisterRef A, llvm::rdf::RegisterRef B) const {
+    return PRI->less(A, B);
+  }
+
+private:
+  // Make it a pointer because apparently some versions of MSVC use std::swap
+  // on the comparator object.
+  const llvm::rdf::PhysicalRegisterInfo *PRI;
+};
+
 struct RegisterAggr {
   RegisterAggr(const PhysicalRegisterInfo &pri)
       : Units(pri.getTRI().getNumRegUnits()), PRI(pri) {}
@@ -334,18 +361,6 @@ template <> struct hash<llvm::rdf::Regis
   }
 };
 
-template <> struct equal_to<llvm::rdf::RegisterRef> {
-  constexpr equal_to(const llvm::rdf::PhysicalRegisterInfo &pri) : PRI(&pri) {}
-
-  bool operator()(llvm::rdf::RegisterRef A, llvm::rdf::RegisterRef B) const {
-    return PRI->equal_to(A, B);
-  }
-
-private:
-  // Make it a pointer just in case. See comment in `less` below.
-  const llvm::rdf::PhysicalRegisterInfo *PRI;
-};
-
 template <> struct equal_to<llvm::rdf::RegisterAggr> {
   bool operator()(const llvm::rdf::RegisterAggr &A,
                   const llvm::rdf::RegisterAggr &B) const {
@@ -353,23 +368,10 @@ template <> struct equal_to<llvm::rdf::R
   }
 };
 
-template <> struct less<llvm::rdf::RegisterRef> {
-  constexpr less(const llvm::rdf::PhysicalRegisterInfo &pri) : PRI(&pri) {}
-
-  bool operator()(llvm::rdf::RegisterRef A, llvm::rdf::RegisterRef B) const {
-    return PRI->less(A, B);
-  }
-
-private:
-  // Make it a pointer because apparently some versions of MSVC use std::swap
-  // on the std::less specialization.
-  const llvm::rdf::PhysicalRegisterInfo *PRI;
-};
-
 } // namespace std
 
 namespace llvm::rdf {
-using RegisterSet = std::set<RegisterRef, std::less<RegisterRef>>;
+using RegisterSet = std::set<RegisterRef, RegisterRefLess>;
 } // namespace llvm::rdf
 
 #endif // LLVM_CODEGEN_RDFREGISTERS_H
