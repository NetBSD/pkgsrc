$NetBSD: patch-curve25519-donna-c64.c,v 1.1 2020/03/22 13:15:14 tnn Exp $

/usr/include/x86_64-linux-gnu/bits/mathcalls-narrow.h:30:20: note: previous declaration of 'fmul' was here
   30 | __MATHCALL_NARROW (__MATHCALL_NAME (mul), __MATHCALL_REDIR_NAME (mul), 2);

--- curve25519-donna-c64.c.orig	2017-04-05 23:25:50.000000000 +0000
+++ curve25519-donna-c64.c
@@ -95,6 +95,7 @@ fscalar_product(felem output, const fele
  * Assumes that in[i] < 2**55 and likewise for in2.
  * On return, output[i] < 2**52
  */
+#define fmul my_fmul
 static inline void force_inline
 fmul(felem output, const felem in2, const felem in) {
   uint128_t t[5];
