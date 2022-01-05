$NetBSD: patch-cpucycles_mips.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Debian patch 0005-fix-cpucycles-mips.patch:
MIPS portability.

--- cpucycles/mips.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ cpucycles/mips.c
@@ -18,7 +18,7 @@ static void readticks(unsigned int *resu
 {
   struct timeval t;
   unsigned int cc;
-  asm volatile(".byte 59; .byte 16; .byte 2; .byte 124; move %0,$2" : "=r"(cc) : : "$2");
+  asm volatile(".long 2080510011; move %0,$2" : "=r"(cc) : : "$2");
   gettimeofday(&t,(struct timezone *) 0);
   result[0] = cc;
   result[1] = t.tv_usec;
