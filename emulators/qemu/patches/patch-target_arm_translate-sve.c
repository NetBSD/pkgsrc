$NetBSD: patch-target_arm_translate-sve.c,v 1.1 2022/10/25 18:46:08 jperkin Exp $

Avoid FSCALE define, notably on SunOS.

--- target/arm/translate-sve.c.orig	2022-08-30 16:41:57.000000000 +0000
+++ target/arm/translate-sve.c
@@ -3988,6 +3988,9 @@ TRANS_FEAT_NONSTREAMING(FTSMUL, aa64_sve
     };                                                          \
     TRANS_FEAT(NAME, FEAT, gen_gvec_fpst_arg_zpzz, name##_zpzz_fns[a->esz], a)
 
+#ifdef FSCALE
+#undef FSCALE
+#endif
 DO_ZPZZ_FP(FADD_zpzz, aa64_sve, sve_fadd)
 DO_ZPZZ_FP(FSUB_zpzz, aa64_sve, sve_fsub)
 DO_ZPZZ_FP(FMUL_zpzz, aa64_sve, sve_fmul)
