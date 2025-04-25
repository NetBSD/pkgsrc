$NetBSD: patch-target_arm_tcg_translate-sve.c,v 1.2 2025/04/25 11:24:29 adam Exp $

Avoid FSCALE define, notably on SunOS.

--- target/arm/tcg/translate-sve.c.orig	2025-04-22 20:26:11.000000000 +0000
+++ target/arm/tcg/translate-sve.c
@@ -3803,6 +3803,9 @@ TRANS_FEAT_NONSTREAMING(FTSMUL, aa64_sve
                s->fpcr_ah ? name##_ah_zpzz_fns[a->esz] :                \
                name##_zpzz_fns[a->esz], a)
 
+#ifdef FSCALE
+#undef FSCALE
+#endif
 DO_ZPZZ_FP(FADD_zpzz, aa64_sve, sve_fadd)
 DO_ZPZZ_FP(FSUB_zpzz, aa64_sve, sve_fsub)
 DO_ZPZZ_FP(FMUL_zpzz, aa64_sve, sve_fmul)
