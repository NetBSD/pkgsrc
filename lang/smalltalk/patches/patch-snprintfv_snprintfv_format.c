$NetBSD: patch-snprintfv_snprintfv_format.c,v 1.2 2015/12/29 23:34:55 dholland Exp $

Avoid name conflict with math.h.

--- snprintfv/snprintfv/format.c.orig	2013-03-23 17:56:22.000000000 +0000
+++ snprintfv/snprintfv/format.c
@@ -55,7 +55,8 @@
 #   define isinfl(x) isnanl ((x) - (x))
 #  endif
 #  ifndef HAVE_MODFL
-static snv_long_double modfl (long double x, long double *exp);
+static snv_long_double my_modfl (long double x, long double *exp);
+#define modfl(x,y) my_modfl(x,y)
 #  endif
 #  ifndef HAVE_COPYSIGNL
 static snv_long_double copysignl (long double x, long double y);
@@ -1098,7 +1099,7 @@ printf_string (STREAM *stream, struct pr
 
 #if !defined NO_FLOAT_PRINTING && defined HAVE_LONG_DOUBLE
 # ifndef HAVE_MODFL
-static long double modfl (long double x, long double *exp)
+static long double my_modfl (long double x, long double *exp)
 {
   /* To compute the integer part of a positive integer (in this case
      abs(X)), sum a big enough integer to the absolute value, so that
