$NetBSD: patch-mpc_src_mpc-impl.h,v 1.1 2018/01/29 14:02:08 adam Exp $

Work around macros removed in mpfr 4.0.0.

--- mpc/src/mpc-impl.h.orig	2018-01-29 13:32:27.000000000 +0000
+++ mpc/src/mpc-impl.h
@@ -60,8 +60,8 @@ along with this program. If not, see htt
    mpfr_setsign (x, y, 0, rnd) : \
    mpfr_copysign (x, y, z, rnd))
    /* work around spurious signs in nan */
-#define MPFR_ADD_ONE_ULP(x) mpfr_add_one_ulp (x, GMP_RNDN)
-#define MPFR_SUB_ONE_ULP(x) mpfr_sub_one_ulp (x, GMP_RNDN)
+#define MPFR_ADD_ONE_ULP(x) (mpfr_sgn(x) > 0 ? mpfr_nextabove(x) : mpfr_nextbelow(x))
+#define MPFR_SUB_ONE_ULP(x) (mpfr_sgn(x) > 0 ? mpfr_nextbelow(x) : mpfr_nextabove(x))
    /* drop unused rounding mode from macroes */
 #define MPFR_SWAP(a,b) do { mpfr_srcptr tmp; tmp = a; a = b; b = tmp; } while (0)
 
