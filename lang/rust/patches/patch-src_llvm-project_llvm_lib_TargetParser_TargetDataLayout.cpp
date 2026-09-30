$NetBSD: patch-src_llvm-project_llvm_lib_TargetParser_TargetDataLayout.cpp,v 1.1 2026/09/30 20:01:29 wiz Exp $

Fix alignment on NetBSD/m68k.
This is also submitted upstream at
https://github.com/llvm/llvm-project/pull/207602

--- src/llvm-project/llvm/lib/TargetParser/TargetDataLayout.cpp.orig	2026-07-05 19:50:17.410753296 +0000
+++ src/llvm-project/llvm/lib/TargetParser/TargetDataLayout.cpp
@@ -122,6 +122,17 @@ static std::string computeLoongArchDataL
   return "e-m:e-p:32:32-i64:64-n32-S128";
 }
 
+// The Linux m68k target uses the ABI used
+// by Sun Microsystems for the old a.out-based binaries: 16-bit
+// alignment of int/long/pointer.
+//
+// NetBSD/m68k on the other hand uses the SVR4 ABI, which
+// aligns int/long/pointer/objects/stack on 32-bit boundaries.
+//
+// For now we just fix this for NetBSD/m68k.
+//
+// Ref. https://github.com/llvm/llvm-project/issues/199826
+
 static std::string computeM68kDataLayout(const Triple &TT) {
   std::string Ret = "";
   // M68k is Big Endian
@@ -131,21 +142,35 @@ static std::string computeM68kDataLayout
   Ret += "-m:e";
 
   // M68k pointers are always 32 bit wide even for 16-bit CPUs.
-  // The ABI only specifies 16-bit alignment.
-  // On at least the 68020+ with a 32-bit bus, there is a performance benefit
-  // to having 32-bit alignment.
-  Ret += "-p:32:16:32";
-
-  // Bytes do not require special alignment, words are word aligned and
-  // long words are word aligned at minimum.
-  Ret += "-i8:8:8-i16:16:16-i32:16:32";
+  if (! TT.isOSNetBSD()) {
+    // The ABI only specifies 16-bit alignment.
+    // On at least the 68020+ with a 32-bit bus, there is a performance benefit
+    // to having 32-bit alignment.
+    Ret += "-p:32:16:32";
+
+    // Bytes do not require special alignment, words are word aligned and
+    // long words are word aligned at minimum.
+    Ret += "-i8:8:8-i16:16:16-i32:16:32";
 
-  // FIXME no floats at the moment
+    // The registers can hold 8, 16, 32 bits
+    Ret += "-n8:16:32";
 
-  // The registers can hold 8, 16, 32 bits
-  Ret += "-n8:16:32";
+    Ret += "-a:0:16-S16";
+  } else {
+    // NetBSD/m68k aligns long/pointer/stack/objects on 32-bits,
+    // ref. comment above.
+    Ret += "-p:32:32:32";
+    // Bytes do not require special alignment,
+    // 16-bit ints are 16-bit aligned and
+    // 32-bit ints are 32-bit aligned
+    Ret += "-i8:8:8-i16:16:16-i32:32:32";
+    // The registers can hold 8, 16, 32 bits
+    Ret += "-n8:16:32";
+    // object and stack alignment is also 32 bits
+    Ret += "-a:0:32-S32";
+  }
 
-  Ret += "-a:0:16-S16";
+  // FIXME no floats at the moment
 
   return Ret;
 }
