$NetBSD: patch-src_gsm0610__rpe.c,v 1.1 2011/09/01 09:22:30 jnemeth Exp $

--- src/gsm0610_rpe.c.orig	2010-07-24 16:28:34.000000000 +0000
+++ src/gsm0610_rpe.c
@@ -82,7 +82,7 @@ static void weighting_filter(int16_t x[4
         " movq 8(%%rax),%%mm2;\n"
         " movq 16(%%rax),%%mm3;\n"
         " movq $0x1000,%%rax;\n"
-        " movq %%rax,%%mm5;\n"              /* For rounding */
+        " movd %%rax,%%mm5;\n"              /* For rounding */
         " xorq %%rsi,%%rsi;\n"
         " .p2align 2;\n"
         "1:\n"
