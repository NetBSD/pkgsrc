$NetBSD: patch-curve25519-donna.c,v 1.1 2020/03/22 13:15:14 tnn Exp $

/usr/include/x86_64-linux-gnu/bits/mathcalls-narrow.h:30:20: note: previous declaration of 'fmul' was here
   30 | __MATHCALL_NARROW (__MATHCALL_NAME (mul), __MATHCALL_REDIR_NAME (mul), 2);

--- curve25519-donna.c.orig	2017-04-05 23:25:50.000000000 +0000
+++ curve25519-donna.c
@@ -324,6 +324,7 @@ static void freduce_coefficients(limb *o
  * output must be distinct to both inputs. The output is reduced degree and
  * reduced coefficient.
  */
+#define fmul my_fmul
 static void
 fmul(limb *output, const limb *in, const limb *in2) {
   limb t[19];
