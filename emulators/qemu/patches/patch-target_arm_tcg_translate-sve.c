$NetBSD: patch-target_arm_tcg_translate-sve.c,v 1.3 2025/08/27 06:27:03 adam Exp $

Avoid FSCALE define, notably on SunOS.

--- target/arm/tcg/translate-sve.c.orig	2025-08-26 18:32:38.000000000 +0000
+++ target/arm/tcg/translate-sve.c
@@ -4238,6 +4238,9 @@ TRANS_FEAT_NONSTREAMING(FTSMUL, aa64_sve
                s->fpcr_ah ? name##_ah_zpzz_fns[a->esz] :                \
                name##_zpzz_fns[a->esz], a)
 
+#ifdef FSCALE
+#undef FSCALE
+#endif
 DO_ZPZZ_FP_B16(FADD_zpzz, aa64_sve, sve_fadd)
 DO_ZPZZ_FP_B16(FSUB_zpzz, aa64_sve, sve_fsub)
 DO_ZPZZ_FP_B16(FMUL_zpzz, aa64_sve, sve_fmul)
