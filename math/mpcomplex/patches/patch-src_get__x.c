$NetBSD: patch-src_get__x.c,v 1.1 2023/10/29 18:06:32 wiz Exp $

Work around bug in SunOS complex.h to make this build with Sun's gcc

--- src/get_x.c.orig	2011-11-04 18:20:19.000000000 +0000
+++ src/get_x.c
@@ -35,6 +35,13 @@ along with this program. If not, see htt
 #include "mpc-impl.h"
 
 #ifdef HAVE_COMPLEX_H
+
+#if defined(__sun) && defined(__GNUC__) && defined(_Imaginary_I)
+#undef I
+#define I	(__extension__ 1.0iF)
+
+#endif
+
 double _Complex
 mpc_get_dc (mpc_srcptr op, mpc_rnd_t rnd) {
    return I * mpfr_get_d (mpc_imagref (op), MPC_RND_IM (rnd))
