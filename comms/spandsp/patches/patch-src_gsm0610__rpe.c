$NetBSD: patch-src_gsm0610__rpe.c,v 1.2 2025/01/22 13:37:55 mef Exp $

date: 2011-09-01 18:22:30 +0900;  author: jnemeth;  state: Exp;
branches:  1.1.2;
Add a patch for PR/44766.  The issue was that older versions of gas
require you to use movd (instead of movq) when transferring data
between reg32/64 and an mmx register.  No PKGREVISION bump since it
failed to compile on amd64 meaning there was no binary package.
----------------------------

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
