$NetBSD: patch-mpc_src_mul.c,v 1.1 2018/01/29 14:02:08 adam Exp $

Avoid conflict with mpfr_fmma introduced in mpfr 4.0.0.

--- mpc/src/mul.c.orig	2018-01-29 13:19:07.000000000 +0000
+++ mpc/src/mul.c
@@ -172,7 +172,7 @@ mul_imag (mpc_ptr z, mpc_srcptr x, mpc_s
 
 
 static int
-mpfr_fmma (mpfr_ptr z, mpfr_srcptr a, mpfr_srcptr b, mpfr_srcptr c,
+gcc_mpfr_fmma (mpfr_ptr z, mpfr_srcptr a, mpfr_srcptr b, mpfr_srcptr c,
            mpfr_srcptr d, int sign, mpfr_rnd_t rnd)
 {
    /* Computes z = ab+cd if sign >= 0, or z = ab-cd if sign < 0.
@@ -337,9 +337,9 @@ mpc_mul_naive (mpc_ptr z, mpc_srcptr x, 
    else
       rop [0] = z [0];
 
-   inex = MPC_INEX (mpfr_fmma (mpc_realref (rop), mpc_realref (x), mpc_realref (y), mpc_imagref (x),
+   inex = MPC_INEX (gcc_mpfr_fmma (mpc_realref (rop), mpc_realref (x), mpc_realref (y), mpc_imagref (x),
                                mpc_imagref (y), -1, MPC_RND_RE (rnd)),
-                    mpfr_fmma (mpc_imagref (rop), mpc_realref (x), mpc_imagref (y), mpc_imagref (x),
+                    gcc_mpfr_fmma (mpc_imagref (rop), mpc_realref (x), mpc_imagref (y), mpc_imagref (x),
                                mpc_realref (y), +1, MPC_RND_IM (rnd)));
 
    mpc_set (z, rop, MPC_RNDNN);
