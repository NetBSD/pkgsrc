$NetBSD: patch-target_hppa_translate.c,v 1.1 2019/04/25 11:33:02 skrll Exp $

--- target/hppa/translate.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ target/hppa/translate.c
@@ -2518,6 +2518,58 @@ static bool trans_pxtlbx(DisasContext *c
 #endif
 }
 
+/* Implement the pcxl and pcxl2 Fast TLB Insert instructions.
+ * See
+ *     https://parisc.wiki.kernel.org/images-parisc/a/a9/Pcxl2_ers.pdf
+ *     page 13-9 (195/206) */
+static bool trans_ixtlbxf(DisasContext *ctx, arg_ixtlbxf *a)
+{
+    CHECK_MOST_PRIVILEGED(EXCP_PRIV_OPR);
+#ifndef CONFIG_USER_ONLY
+    TCGv_tl addr;
+    TCGv_reg reg;
+    TCGv_reg ar, sr;
+    TCGv_tl atl, stl;
+
+    nullify_over(ctx);
+
+/*    if (not (pcxl or pcxl2))
+          return gen_illegal(ctx); */
+
+    ar = get_temp(ctx);
+    sr = get_temp(ctx);
+    atl = get_temp_tl(ctx);
+    stl = get_temp_tl(ctx);
+    addr = get_temp_tl(ctx);
+
+
+    if (a->data) {
+        tcg_gen_ld_reg(sr, cpu_env, offsetof(CPUHPPAState, cr[CR_ISR]));
+        tcg_gen_ld_reg(ar, cpu_env, offsetof(CPUHPPAState, cr[CR_IOR]));
+    } else {
+        tcg_gen_ld_reg(sr, cpu_env, offsetof(CPUHPPAState, cr[CR_IIASQ]));
+        tcg_gen_ld_reg(ar, cpu_env, offsetof(CPUHPPAState, cr[CR_IIAOQ]));
+    }
+
+    tcg_gen_extu_reg_tl(atl, ar);
+    tcg_gen_extu_reg_tl(stl, sr);
+    tcg_gen_shli_i64(stl, stl, 32);
+    tcg_gen_or_tl(addr, atl, stl);
+    reg = load_gpr(ctx, a->r);
+    if (a->addr) {
+        gen_helper_itlba(cpu_env, addr, reg);
+    } else {
+        gen_helper_itlbp(cpu_env, addr, reg);
+    }
+
+    /* Exit TB for TLB change if mmu is enabled.  */
+    if (ctx->tb_flags & PSW_C) {
+        ctx->base.is_jmp = DISAS_IAQ_N_STALE;
+    }
+    return nullify_end(ctx);
+#endif
+}
+
 static bool trans_lpa(DisasContext *ctx, arg_ldst *a)
 {
     CHECK_MOST_PRIVILEGED(EXCP_PRIV_OPR);
