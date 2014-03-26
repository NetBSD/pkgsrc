$NetBSD: patch-ext_linalg__complex.c,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- ext/linalg_complex.c.orig	2014-03-25 15:47:30.000000000 +0000
+++ ext/linalg_complex.c
@@ -51,8 +51,12 @@ VALUE rb_gsl_linalg_complex_LU_decomp(in
   case 0:
     p = gsl_permutation_alloc(size);
     gsl_linalg_complex_LU_decomp(m, p, &signum);
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+      rb_obj_reveal((itmp == 1)? argv[0]: obj, cgsl_matrix_complex_LU);
+#else
     if (itmp == 1) RBASIC(argv[0])->klass = cgsl_matrix_complex_LU;
     else RBASIC(obj)->klass = cgsl_matrix_complex_LU;
+#endif
     obj2 = Data_Wrap_Struct(cgsl_permutation, 0, gsl_permutation_free, p);
     return rb_ary_new3(2, obj2, INT2FIX(signum));
     break;
@@ -60,8 +64,12 @@ VALUE rb_gsl_linalg_complex_LU_decomp(in
     CHECK_PERMUTATION(argv[itmp]);
     Data_Get_Struct(argv[itmp], gsl_permutation, p);
     gsl_linalg_complex_LU_decomp(m, p, &signum);
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal((itmp == 1)? argv[0]: obj, cgsl_matrix_complex_LU);
+#else
     if (itmp == 1) RBASIC(argv[0])->klass = cgsl_matrix_complex_LU;
     else RBASIC(obj)->klass = cgsl_matrix_complex_LU;
+#endif
     return INT2FIX(signum);
     break;
   default:
