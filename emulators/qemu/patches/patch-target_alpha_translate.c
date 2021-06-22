$NetBSD: patch-target_alpha_translate.c,v 1.1 2021/06/22 04:09:06 thorpej Exp $

Patch from upstream (not integrated there yet) to require FEN to be
enabled for floating point operations, and to properly deliver FEN
traps if not.  Fixes many users of floating point (jot(1), awk(1), etc.)
on NetBSD/alpha under Qemu.

    https://gitlab.com/qemu-project/qemu/-/issues/438

--- target/alpha/translate.c.orig	2021-04-29 17:18:59.000000000 +0000
+++ target/alpha/translate.c	2021-06-22 00:26:30.693822791 +0000
@@ -1471,6 +1471,13 @@ static DisasJumpType gen_mtpr(DisasConte
         }                                       \
     } while (0)
 
+#define REQUIRE_FEN                             \
+    do {                                        \
+        if (!(ctx->tbflags & ENV_FLAG_FEN)) {   \
+            goto raise_fen;                     \
+        }                                       \
+    } while (0)
+
 static DisasJumpType translate_one(DisasContext *ctx, uint32_t insn)
 {
     int32_t disp21, disp16, disp12 __attribute__((unused));
@@ -2066,6 +2073,7 @@ static DisasJumpType translate_one(Disas
         case 0x04:
             /* ITOFS */
             REQUIRE_REG_31(rb);
+            REQUIRE_FEN;
             t32 = tcg_temp_new_i32();
             va = load_gpr(ctx, ra);
             tcg_gen_extrl_i64_i32(t32, va);
@@ -2075,17 +2083,20 @@ static DisasJumpType translate_one(Disas
         case 0x0A:
             /* SQRTF */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             vb = load_fpr(ctx, rb);
             gen_helper_sqrtf(vc, cpu_env, vb);
             break;
         case 0x0B:
             /* SQRTS */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_sqrts(ctx, rb, rc, fn11);
             break;
         case 0x14:
             /* ITOFF */
             REQUIRE_REG_31(rb);
+            REQUIRE_FEN;
             t32 = tcg_temp_new_i32();
             va = load_gpr(ctx, ra);
             tcg_gen_extrl_i64_i32(t32, va);
@@ -2095,18 +2106,21 @@ static DisasJumpType translate_one(Disas
         case 0x24:
             /* ITOFT */
             REQUIRE_REG_31(rb);
+            REQUIRE_FEN;
             va = load_gpr(ctx, ra);
             tcg_gen_mov_i64(vc, va);
             break;
         case 0x2A:
             /* SQRTG */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             vb = load_fpr(ctx, rb);
             gen_helper_sqrtg(vc, cpu_env, vb);
             break;
         case 0x02B:
             /* SQRTT */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_sqrtt(ctx, rb, rc, fn11);
             break;
         default:
@@ -2123,18 +2137,22 @@ static DisasJumpType translate_one(Disas
         switch (fpfn) { /* fn11 & 0x3F */
         case 0x00:
             /* ADDF */
+            REQUIRE_FEN;
             gen_helper_addf(vc, cpu_env, va, vb);
             break;
         case 0x01:
             /* SUBF */
+            REQUIRE_FEN;
             gen_helper_subf(vc, cpu_env, va, vb);
             break;
         case 0x02:
             /* MULF */
+            REQUIRE_FEN;
             gen_helper_mulf(vc, cpu_env, va, vb);
             break;
         case 0x03:
             /* DIVF */
+            REQUIRE_FEN;
             gen_helper_divf(vc, cpu_env, va, vb);
             break;
         case 0x1E:
@@ -2143,35 +2161,43 @@ static DisasJumpType translate_one(Disas
             goto invalid_opc;
         case 0x20:
             /* ADDG */
+            REQUIRE_FEN;
             gen_helper_addg(vc, cpu_env, va, vb);
             break;
         case 0x21:
             /* SUBG */
+            REQUIRE_FEN;
             gen_helper_subg(vc, cpu_env, va, vb);
             break;
         case 0x22:
             /* MULG */
+            REQUIRE_FEN;
             gen_helper_mulg(vc, cpu_env, va, vb);
             break;
         case 0x23:
             /* DIVG */
+            REQUIRE_FEN;
             gen_helper_divg(vc, cpu_env, va, vb);
             break;
         case 0x25:
             /* CMPGEQ */
+            REQUIRE_FEN;
             gen_helper_cmpgeq(vc, cpu_env, va, vb);
             break;
         case 0x26:
             /* CMPGLT */
+            REQUIRE_FEN;
             gen_helper_cmpglt(vc, cpu_env, va, vb);
             break;
         case 0x27:
             /* CMPGLE */
+            REQUIRE_FEN;
             gen_helper_cmpgle(vc, cpu_env, va, vb);
             break;
         case 0x2C:
             /* CVTGF */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_helper_cvtgf(vc, cpu_env, vb);
             break;
         case 0x2D:
@@ -2181,16 +2207,19 @@ static DisasJumpType translate_one(Disas
         case 0x2F:
             /* CVTGQ */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_helper_cvtgq(vc, cpu_env, vb);
             break;
         case 0x3C:
             /* CVTQF */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_helper_cvtqf(vc, cpu_env, vb);
             break;
         case 0x3E:
             /* CVTQG */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_helper_cvtqg(vc, cpu_env, vb);
             break;
         default:
@@ -2203,54 +2232,67 @@ static DisasJumpType translate_one(Disas
         switch (fpfn) { /* fn11 & 0x3F */
         case 0x00:
             /* ADDS */
+            REQUIRE_FEN;
             gen_adds(ctx, ra, rb, rc, fn11);
             break;
         case 0x01:
             /* SUBS */
+            REQUIRE_FEN;
             gen_subs(ctx, ra, rb, rc, fn11);
             break;
         case 0x02:
             /* MULS */
+            REQUIRE_FEN;
             gen_muls(ctx, ra, rb, rc, fn11);
             break;
         case 0x03:
             /* DIVS */
+            REQUIRE_FEN;
             gen_divs(ctx, ra, rb, rc, fn11);
             break;
         case 0x20:
             /* ADDT */
+            REQUIRE_FEN;
             gen_addt(ctx, ra, rb, rc, fn11);
             break;
         case 0x21:
             /* SUBT */
+            REQUIRE_FEN;
             gen_subt(ctx, ra, rb, rc, fn11);
             break;
         case 0x22:
             /* MULT */
+            REQUIRE_FEN;
             gen_mult(ctx, ra, rb, rc, fn11);
             break;
         case 0x23:
             /* DIVT */
+            REQUIRE_FEN;
             gen_divt(ctx, ra, rb, rc, fn11);
             break;
         case 0x24:
             /* CMPTUN */
+            REQUIRE_FEN;
             gen_cmptun(ctx, ra, rb, rc, fn11);
             break;
         case 0x25:
             /* CMPTEQ */
+            REQUIRE_FEN;
             gen_cmpteq(ctx, ra, rb, rc, fn11);
             break;
         case 0x26:
             /* CMPTLT */
+            REQUIRE_FEN;
             gen_cmptlt(ctx, ra, rb, rc, fn11);
             break;
         case 0x27:
             /* CMPTLE */
+            REQUIRE_FEN;
             gen_cmptle(ctx, ra, rb, rc, fn11);
             break;
         case 0x2C:
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             if (fn11 == 0x2AC || fn11 == 0x6AC) {
                 /* CVTST */
                 gen_cvtst(ctx, rb, rc, fn11);
@@ -2262,16 +2304,19 @@ static DisasJumpType translate_one(Disas
         case 0x2F:
             /* CVTTQ */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_cvttq(ctx, rb, rc, fn11);
             break;
         case 0x3C:
             /* CVTQS */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_cvtqs(ctx, rb, rc, fn11);
             break;
         case 0x3E:
             /* CVTQT */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             gen_cvtqt(ctx, rb, rc, fn11);
             break;
         default:
@@ -2284,12 +2329,14 @@ static DisasJumpType translate_one(Disas
         case 0x010:
             /* CVTLQ */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             vc = dest_fpr(ctx, rc);
             vb = load_fpr(ctx, rb);
             gen_cvtlq(vc, vb);
             break;
         case 0x020:
             /* CPYS */
+            REQUIRE_FEN;
             if (rc == 31) {
                 /* Special case CPYS as FNOP.  */
             } else {
@@ -2306,6 +2353,7 @@ static DisasJumpType translate_one(Disas
             break;
         case 0x021:
             /* CPYSN */
+            REQUIRE_FEN;
             vc = dest_fpr(ctx, rc);
             vb = load_fpr(ctx, rb);
             va = load_fpr(ctx, ra);
@@ -2313,6 +2361,7 @@ static DisasJumpType translate_one(Disas
             break;
         case 0x022:
             /* CPYSE */
+            REQUIRE_FEN;
             vc = dest_fpr(ctx, rc);
             vb = load_fpr(ctx, rb);
             va = load_fpr(ctx, ra);
@@ -2320,6 +2369,7 @@ static DisasJumpType translate_one(Disas
             break;
         case 0x024:
             /* MT_FPCR */
+            REQUIRE_FEN;
             va = load_fpr(ctx, ra);
             gen_helper_store_fpcr(cpu_env, va);
             if (ctx->tb_rm == QUAL_RM_D) {
@@ -2330,37 +2380,45 @@ static DisasJumpType translate_one(Disas
             break;
         case 0x025:
             /* MF_FPCR */
+            REQUIRE_FEN;
             va = dest_fpr(ctx, ra);
             gen_helper_load_fpcr(va, cpu_env);
             break;
         case 0x02A:
             /* FCMOVEQ */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_EQ, ra, rb, rc);
             break;
         case 0x02B:
             /* FCMOVNE */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_NE, ra, rb, rc);
             break;
         case 0x02C:
             /* FCMOVLT */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_LT, ra, rb, rc);
             break;
         case 0x02D:
             /* FCMOVGE */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_GE, ra, rb, rc);
             break;
         case 0x02E:
             /* FCMOVLE */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_LE, ra, rb, rc);
             break;
         case 0x02F:
             /* FCMOVGT */
+            REQUIRE_FEN;
             gen_fcmov(ctx, TCG_COND_GT, ra, rb, rc);
             break;
         case 0x030: /* CVTQL */
         case 0x130: /* CVTQL/V */
         case 0x530: /* CVTQL/SV */
             REQUIRE_REG_31(ra);
+            REQUIRE_FEN;
             vc = dest_fpr(ctx, rc);
             vb = load_fpr(ctx, rb);
             gen_helper_cvtql(vc, cpu_env, vb);
@@ -2793,34 +2851,42 @@ static DisasJumpType translate_one(Disas
 #endif
     case 0x20:
         /* LDF */
+        REQUIRE_FEN;
         gen_load_mem(ctx, &gen_qemu_ldf, ra, rb, disp16, 1, 0);
         break;
     case 0x21:
         /* LDG */
+        REQUIRE_FEN;
         gen_load_mem(ctx, &gen_qemu_ldg, ra, rb, disp16, 1, 0);
         break;
     case 0x22:
         /* LDS */
+        REQUIRE_FEN;
         gen_load_mem(ctx, &gen_qemu_lds, ra, rb, disp16, 1, 0);
         break;
     case 0x23:
         /* LDT */
+        REQUIRE_FEN;
         gen_load_mem(ctx, &tcg_gen_qemu_ld64, ra, rb, disp16, 1, 0);
         break;
     case 0x24:
         /* STF */
+        REQUIRE_FEN;
         gen_store_mem(ctx, &gen_qemu_stf, ra, rb, disp16, 1, 0);
         break;
     case 0x25:
         /* STG */
+        REQUIRE_FEN;
         gen_store_mem(ctx, &gen_qemu_stg, ra, rb, disp16, 1, 0);
         break;
     case 0x26:
         /* STS */
+        REQUIRE_FEN;
         gen_store_mem(ctx, &gen_qemu_sts, ra, rb, disp16, 1, 0);
         break;
     case 0x27:
         /* STT */
+        REQUIRE_FEN;
         gen_store_mem(ctx, &tcg_gen_qemu_st64, ra, rb, disp16, 1, 0);
         break;
     case 0x28:
@@ -2862,12 +2928,15 @@ static DisasJumpType translate_one(Disas
         ret = gen_bdirect(ctx, ra, disp21);
         break;
     case 0x31: /* FBEQ */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_EQ, ra, disp21);
         break;
     case 0x32: /* FBLT */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_LT, ra, disp21);
         break;
     case 0x33: /* FBLE */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_LE, ra, disp21);
         break;
     case 0x34:
@@ -2875,12 +2944,15 @@ static DisasJumpType translate_one(Disas
         ret = gen_bdirect(ctx, ra, disp21);
         break;
     case 0x35: /* FBNE */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_NE, ra, disp21);
         break;
     case 0x36: /* FBGE */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_GE, ra, disp21);
         break;
     case 0x37: /* FBGT */
+        REQUIRE_FEN;
         ret = gen_fbcond(ctx, TCG_COND_GT, ra, disp21);
         break;
     case 0x38:
@@ -2918,6 +2990,9 @@ static DisasJumpType translate_one(Disas
     invalid_opc:
         ret = gen_invalid(ctx);
         break;
+    raise_fen:
+        ret = gen_excp(ctx, EXCP_FEN, 0);
+        break;
     }
 
     return ret;
