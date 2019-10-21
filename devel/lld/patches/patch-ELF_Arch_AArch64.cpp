$NetBSD: patch-ELF_Arch_AArch64.cpp,v 1.1 2019/10/21 22:07:58 rjs Exp $

Set correct base address on NetBSD.

--- ELF/Arch/AArch64.cpp.orig	2019-07-16 05:50:45.000000000 +0000
+++ ELF/Arch/AArch64.cpp
@@ -66,9 +66,12 @@ AArch64::AArch64() {
   pltHeaderSize = 32;
   defaultMaxPageSize = 65536;
 
-  // Align to the 2 MiB page size (known as a superpage or huge page).
-  // FreeBSD automatically promotes 2 MiB-aligned allocations.
-  defaultImageBase = 0x200000;
+  if (config->targetTriple.isOSNetBSD())
+    defaultImageBase = 0x200100000;
+  else
+    // Align to the 2 MiB page size (known as a superpage or huge page).
+    // FreeBSD automatically promotes 2 MiB-aligned allocations.
+    defaultImageBase = 0x200000;
 
   needsThunks = true;
 }
