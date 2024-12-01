$NetBSD: patch-src_zm__utils.cpp,v 1.4 2024/12/01 13:49:48 gdt Exp $

Avoid assuming linux on arm.  For now, assume neon.

Fix time types (sizes).

--- src/zm_utils.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_utils.cpp
@@ -183,7 +183,7 @@ std::string TimevalToString(timeval tv) 
     return "";
   }
 
-  return stringtf("%s.%06ld", tm_buf.data(), tv.tv_usec);
+  return stringtf("%s.%06ld", tm_buf.data(), (long) tv.tv_usec);
 }
 
 /* Detect special hardware features, such as SIMD instruction sets */
@@ -231,13 +231,15 @@ void HwCapsDetect() {
   unsigned long auxval = 0;
   elf_aux_info(AT_HWCAP, &auxval, sizeof(auxval));
   if (auxval & HWCAP_NEON) {
-  #error Unsupported OS.
-  #endif
     Debug(1,"Detected ARM (AArch32) processor with Neon");
     neonversion = 1;
   } else {
     Debug(1,"Detected ARM (AArch32) processor");
   }
+#  else
+    Debug(1,"!!ASSUMING!! ARM (AArch32) processor with Neon");
+    neonversion = 1;
+#  endif
 #elif defined(__aarch64__)
   // ARM processor in 64bit mode
   // Neon is mandatory, no need to check for it
