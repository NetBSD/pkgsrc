$NetBSD: patch-ext_matrix__complex.c,v 1.1 2011/05/10 11:23:48 taca Exp $

Avoid the same function name on new gsl.

--- ext/matrix_complex.c.orig	2010-11-10 21:43:10.000000000 +0000
+++ ext/matrix_complex.c
@@ -1520,7 +1520,7 @@ static VALUE rb_gsl_matrix_complex_indge
 }
 
 
-static int gsl_matrix_complex_equal(const gsl_matrix_complex *m1,
+static int _gsl_matrix_complex_equal(const gsl_matrix_complex *m1,
   const gsl_matrix_complex *m2, double eps)
 {
   gsl_complex z1, z2;
@@ -1555,7 +1555,7 @@ static VALUE rb_gsl_matrix_complex_equal
   Data_Get_Struct(obj, gsl_matrix_complex, m1);
   CHECK_MATRIX_COMPLEX(argv[0]);
   Data_Get_Struct(argv[0], gsl_matrix_complex, m2);
-  ret = gsl_matrix_complex_equal(m1, m2, eps);
+  ret = _gsl_matrix_complex_equal(m1, m2, eps);
   if (ret == 1) return Qtrue;
   else return Qfalse;
 }
