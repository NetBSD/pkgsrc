$NetBSD: patch-ELF_Config.h,v 1.5 2019/11/03 12:10:29 kamil Exp $

Cherry-pick upstream patch commit 2a0fcae3d4d1fd85d6ae8378d7c6f12430c0087d
[lld] [ELF] Add '-z nognustack' opt to suppress emitting PT_GNU_STAC dummy option for an AArch64 erratum.

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2019-07-16 05:50:45.000000000 +0000
+++ ELF/Config.h
@@ -61,6 +61,9 @@ enum class Target2Policy { Abs, Rel, Got
 // For tracking ARM Float Argument PCS
 enum class ARMVFPArgKind { Default, Base, VFP, ToolChain };
 
+// For -z *stack
+enum class GnuStackKind { None, Exec, NoExec };
+
 struct SymbolVersion {
   llvm::StringRef name;
   bool isExternCpp;
@@ -146,6 +149,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool forceBTI;
   bool formatBinary = false;
@@ -214,6 +218,7 @@ struct Configuration {
   bool zRetpolineplt;
   bool zWxneeded;
   DiscardPolicy discard;
+  GnuStackKind zGnustack;
   ICFLevel icf;
   OrphanHandlingPolicy orphanHandling;
   SortSectionPolicy sortSection;
