$NetBSD: patch-ELF_Config.h,v 1.2 2019/06/02 08:37:39 adam Exp $

Add support for customizing LLD behavior on target triple.
https://reviews.llvm.org/D56650

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

--- ELF/Config.h.orig	2019-01-17 13:46:36.000000000 +0000
+++ ELF/Config.h
@@ -14,6 +14,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -194,6 +195,7 @@ struct Configuration {
   bool ZNodefaultlib;
   bool ZNodelete;
   bool ZNodlopen;
+  bool ZNognustack;
   bool ZNow;
   bool ZOrigin;
   bool ZRelro;
@@ -277,6 +279,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int Wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple TargetTriple;
 };
 
 // The only instance of Configuration struct.
