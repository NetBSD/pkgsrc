$NetBSD: patch-ELF_Config.h,v 1.4 2019/10/21 22:07:58 rjs Exp $

Add support for customizing LLD behavior on target triple.
https://reviews.llvm.org/D56650

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2019-07-16 05:50:45.000000000 +0000
+++ ELF/Config.h
@@ -13,6 +13,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -61,6 +62,9 @@ enum class Target2Policy { Abs, Rel, Got
 // For tracking ARM Float Argument PCS
 enum class ARMVFPArgKind { Default, Base, VFP, ToolChain };
 
+// For -z *stack
+enum class GnuStackKind { None, Exec, NoExec };
+
 struct SymbolVersion {
   llvm::StringRef name;
   bool isExternCpp;
@@ -146,6 +150,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool forceBTI;
   bool formatBinary = false;
@@ -206,6 +211,7 @@ struct Configuration {
   bool zNodefaultlib;
   bool zNodelete;
   bool zNodlopen;
+  bool zNognustack;
   bool zNow;
   bool zOrigin;
   bool zRelro;
@@ -214,6 +220,7 @@ struct Configuration {
   bool zRetpolineplt;
   bool zWxneeded;
   DiscardPolicy discard;
+  GnuStackKind zGnustack;
   ICFLevel icf;
   OrphanHandlingPolicy orphanHandling;
   SortSectionPolicy sortSection;
@@ -304,6 +311,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple targetTriple;
 };
 
 // The only instance of Configuration struct.
