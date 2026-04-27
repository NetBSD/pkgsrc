$NetBSD: patch-target_arm_tcg_translate-sve.c,v 1.4 2026/04/27 10:25:01 adam Exp $

Avoid FSCALE define, notably on SunOS.

--- target/arm/tcg/translate-sve.c.orig	2026-04-21 19:36:26.000000000 +0000
+++ target/arm/tcg/translate-sve.c
@@ -4241,6 +4241,9 @@ TRANS_FEAT_NONSTREAMING(FTSMUL, aa64_sve
                s->fpcr_ah ? name##_ah_zpzz_fns[a->esz] :                \
                name##_zpzz_fns[a->esz], a)
 
+#ifdef FSCALE
+#undef FSCALE
+#endif
 DO_ZPZZ_FP_B16(FADD_zpzz, aa64_sme_or_sve, sve_fadd)
 DO_ZPZZ_FP_B16(FSUB_zpzz, aa64_sme_or_sve, sve_fsub)
 DO_ZPZZ_FP_B16(FMUL_zpzz, aa64_sme_or_sve, sve_fmul)
