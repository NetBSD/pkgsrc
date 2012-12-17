$NetBSD: patch-src_main_format.c,v 1.3 2012/12/17 09:08:47 wen Exp $

NetBSD does not have rintl() or floorl() so use the OpenBSD implementation
of rintl() in that case.  The same case exists for DragonFly.

--- src/main/format.c.orig	2012-04-15 22:05:34.000000000 +0000
+++ src/main/format.c
@@ -130,6 +130,7 @@ void formatInteger(int *x, int n, int *f
 # define R_nearbyintl rintl
 # else
 # define R_nearbyintl private_nearbyintl
+# if !defined(__NetBSD__) && !defined(__DragonFly__)
 long double private_nearbyintl(long double x)
 {
     long double x1;
@@ -142,6 +143,55 @@ long double private_nearbyintl(long doub
         if (x/2.0 == floorl(x/2.0)) return(x); else return(x1);
     }
 }
+# else
+#include <machine/ieee.h>
+
+#if LDBL_MAX_EXP != 0x4000
+/* We also require the usual bias, min exp and expsign packing. */
+#error "Unsupported long double format"
+#endif
+
+#define BIAS    (LDBL_MAX_EXP - 1)
+
+static const float
+shift[2] = {
+#if LDBL_MANT_DIG == 64
+        0x1.0p63, -0x1.0p63
+#elif LDBL_MANT_DIG == 113
+        0x1.0p112, -0x1.0p112
+#else
+#error "Unsupported long double format"
+#endif
+};
+static const float zero[2] = { 0.0, -0.0 };
+
+long double private_nearbyintl(long double x)
+{
+        union {
+                long double e;
+                struct ieee_ext bits;
+        } u;
+        uint32_t expsign;
+        int ex, sign;
+        u.e = x;
+        expsign = (u.bits.ext_sign << 15) | u.bits.ext_exp;
+        ex = expsign & 0x7fff;
+
+        if (ex >= BIAS + LDBL_MANT_DIG - 1) {
+                if (ex == BIAS + LDBL_MAX_EXP)
+                        return (x + x); /* Inf, NaN, or unsupported format */
+                return (x);             /* finite and already an integer */
+        }
+        sign = expsign >> 15;
+        x += shift[sign];
+        x -= shift[sign];
+
+        if (ex < BIAS && x == 0.0L)
+                return (zero[sign]);
+
+        return (x);
+}
+# endif
 # endif
 # else /* no long double */
 # ifdef HAVE_NEARBYINT
