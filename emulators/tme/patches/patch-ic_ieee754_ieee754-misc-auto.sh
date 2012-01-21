$NetBSD: patch-ic_ieee754_ieee754-misc-auto.sh,v 1.1 2012/01/21 04:41:44 tsutsui Exp $

Suppress undefined macro warnings by cpp in newer gcc 4.5.3 on NetBSD/arm.

--- ic/ieee754/ieee754-misc-auto.sh.orig	2007-08-24 01:05:43.000000000 +0000
+++ ic/ieee754/ieee754-misc-auto.sh
@@ -106,7 +106,7 @@ typedef float tme_ieee754_${precision}_b
 #elif (TME_FLOAT_FORMAT_IEEE754_${capprecision}_BUILTIN == TME_FLOAT_FORMAT_DOUBLE)
 typedef double tme_ieee754_${precision}_builtin_t;
 #define tme_float_value_ieee754_${precision}_builtin tme_float_value_double
-#elif (TME_FLOAT_FORMAT_IEEE754_${capprecision}_BUILTIN == TME_FLOAT_FORMAT_LONG_DOUBLE)
+#elif (defined(_TME_HAVE_LONG_DOUBLE) && (TME_FLOAT_FORMAT_IEEE754_${capprecision}_BUILTIN == TME_FLOAT_FORMAT_LONG_DOUBLE))
 typedef long double tme_ieee754_${precision}_builtin_t;
 #define tme_float_value_ieee754_${precision}_builtin tme_float_value_long_double
 #endif
