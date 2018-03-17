$NetBSD: patch-src_cpu_cpu__jitc__x86__64_ppc__mmu.cc,v 1.1 2018/03/17 01:27:55 ryoon Exp $

* Support platforms that does not define MAP_32BIT, for example NetBSD.

--- src/cpu/cpu_jitc_x86_64/ppc_mmu.cc.orig	2011-07-12 20:57:24.000000000 +0000
+++ src/cpu/cpu_jitc_x86_64/ppc_mmu.cc
@@ -37,6 +37,10 @@
 byte *gMemory = NULL;
 uint32 gMemorySize;
 
+#ifndef MAP_32BIT
+#define MAP_32BIT 0
+#endif
+
 #undef TLB
 
 static int ppc_pte_protection[] = {
