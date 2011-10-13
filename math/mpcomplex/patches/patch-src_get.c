$NetBSD: patch-src_get.c,v 1.1 2011/10/13 13:22:46 hans Exp $

--- src/get.c.orig	2011-01-26 09:47:17.000000000 +0100
+++ src/get.c	2011-10-13 01:09:15.618498023 +0200
@@ -28,6 +28,13 @@ MA 02111-1307, USA. */
 #include "mpc-impl.h"
 
 #if defined _MPC_H_HAVE_COMPLEX
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
