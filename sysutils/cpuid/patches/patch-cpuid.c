$NetBSD: patch-cpuid.c,v 1.1 2026/06/24 14:11:22 wiz Exp $

Add missing header for exit().

--- cpuid.c.orig	2026-06-24 14:10:21.747416612 +0000
+++ cpuid.c
@@ -14,6 +14,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 void decode_intel_tlb(int);
 void decode_cyrix_tlb(int);
