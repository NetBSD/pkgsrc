$NetBSD: patch-src_zm__utils.cpp,v 1.6 2026/10/11 00:04:42 gdt Exp $

Hack around arm detection woes.

\todo Fix/upstream.

--- src/zm_utils.cpp.orig	2026-10-05 23:07:17.000000000 +0000
+++ src/zm_utils.cpp
@@ -291,8 +291,8 @@ void HwCapsDetect() {
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
