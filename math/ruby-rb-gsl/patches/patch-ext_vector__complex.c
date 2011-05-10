$NetBSD: patch-ext_vector__complex.c,v 1.1 2011/05/10 11:23:48 taca Exp $

Avoid the same function name on new gsl.

--- ext/vector_complex.c.orig	2011-02-14 22:59:45.000000000 +0000
+++ ext/vector_complex.c
@@ -1986,7 +1986,7 @@ static VALUE rb_gsl_vector_complex_zip(i
   return ary;
 }
 
-static int gsl_vector_complex_equal(const gsl_vector_complex *v1,
+static int _gsl_vector_complex_equal(const gsl_vector_complex *v1,
   const gsl_vector_complex *v2, double eps)
 {
   gsl_complex z1, z2;
@@ -2019,7 +2019,7 @@ static VALUE rb_gsl_vector_complex_equal
   Data_Get_Struct(obj, gsl_vector_complex, v1);
   CHECK_VECTOR_COMPLEX(argv[0]);
   Data_Get_Struct(argv[0], gsl_vector_complex, v2);
-  ret = gsl_vector_complex_equal(v1, v2, eps);
+  ret = _gsl_vector_complex_equal(v1, v2, eps);
   if (ret == 1) return Qtrue;
   else return Qfalse;
 }
