$NetBSD: patch-src_cpu_fpp__native.c,v 1.1 2020/07/10 19:33:30 adam Exp $

Build on system without lrintl, remainderl, log1pl, expm1l, log2l.

--- src/cpu/fpp_native.c.orig	2020-07-10 19:16:32.000000000 +0000
+++ src/cpu/fpp_native.c
@@ -507,7 +507,7 @@ static uae_s64 fp_to_int(fpdata *src, in
 		fp = fxsizes[size * 2 + 1];
 	}
 #if USE_HOST_ROUNDING
-	return lrintl(fp);
+	return lrint(fp);
 #else
 	uae_s64 result = (int)fp;
 	switch (regs.fpcr & 0x30)
@@ -762,7 +762,7 @@ static void fp_rem(fpdata *a, fpdata *b,
         *s = 0;
     }
     *q = (uae_u64)quot;
-    a->fp = remainderl(a->fp, b->fp);
+    a->fp = remainder(a->fp, b->fp);
 	fp_round(a);
 }
 
@@ -799,14 +799,14 @@ static void fp_sqrt(fpdata *a, fpdata *b
 static void fp_lognp1(fpdata *a, fpdata *b)
 {
 	fp_normal_prec();
-	a->fp = log1pl(b->fp);
+	a->fp = log1p(b->fp);
 	fp_reset_normal_prec();
 	fp_round(a);
 }
 static void fp_etoxm1(fpdata *a, fpdata *b)
 {
 	fp_normal_prec();
-	a->fp = expm1l(b->fp);
+	a->fp = expm1(b->fp);
 	fp_reset_normal_prec();
 	fp_round(a);
 }
@@ -890,7 +890,7 @@ static void fp_log10(fpdata *a, fpdata *
 static void fp_log2(fpdata *a, fpdata *b)
 {
 	fp_normal_prec();
-	a->fp = log2l(b->fp);
+	a->fp = log2(b->fp);
 	fp_reset_normal_prec();
 	fp_round(a);
 }
