$NetBSD: patch-src_zm__utils.cpp,v 1.5 2026/07/30 12:36:00 gdt Exp $

Fix time types.

Hack around arm detection woes.

\todo Send time upstream and fix arm problems.

--- src/zm_utils.cpp.orig	2026-05-28 12:42:49.000000000 +0000
+++ src/zm_utils.cpp
@@ -215,7 +215,7 @@ std::string TimevalToString(timeval tv) 
     return "";
   }
 
-  return stringtf("%s.%06ld", tm_buf.data(), tv.tv_usec);
+  return stringtf("%s.%06ld", tm_buf.data(), (long) tv.tv_usec);
 }
 
 /* Detect special hardware features, such as SIMD instruction sets */
@@ -264,8 +264,8 @@ void HwCapsDetect() {
   elf_aux_info(AT_HWCAP, &auxval, sizeof(auxval));
   if (auxval & HWCAP_NEON) {
 #else
-  {
-#error Unsupported OS.
+#   warning COULD NOT DETECT NEON - ASSUMING NOT PRESENT
+    if (0) {
 #endif
     Debug(1,"Detected ARM (AArch32) processor with Neon");
     neonversion = 1;
