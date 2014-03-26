$NetBSD: patch-ext_linalg.c,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- ext/linalg.c.orig	2014-03-25 15:47:30.000000000 +0000
+++ ext/linalg.c
@@ -71,7 +71,11 @@ static VALUE rb_gsl_linalg_LU_decomposit
   Data_Get_Struct(omatrix, gsl_matrix, mtmp);
   if (flag == LINALG_DECOMP_BANG) {
     m = mtmp;
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(omatrix, cgsl_matrix_LU);
+#else
     RBASIC(omatrix)->klass = cgsl_matrix_LU;
+#endif
     objm = omatrix;
   } else {
     m = make_matrix_clone(mtmp);
@@ -692,7 +696,11 @@ static VALUE rb_gsl_linalg_QR_LQ_decompo
     fdecomp = &gsl_linalg_QR_decomp;
     m = mtmp;
     mdecomp = omatrix;
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(mdecomp, cgsl_matrix_QR);
+#else
     RBASIC(mdecomp)->klass = cgsl_matrix_QR;
+#endif
     break;
 #ifdef GSL_1_6_LATER
   case LINALG_LQ_DECOMP:
@@ -704,7 +712,11 @@ static VALUE rb_gsl_linalg_QR_LQ_decompo
     fdecomp = &gsl_linalg_LQ_decomp;
     m = mtmp;
     mdecomp = omatrix;
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(mdecomp, cgsl_matrix_LQ);
+#else
     RBASIC(mdecomp)->klass = cgsl_matrix_LQ;
+#endif
     break;
 #endif
   default:
@@ -731,7 +743,11 @@ static VALUE rb_gsl_linalg_QR_LQ_decompo
       vtau = Data_Wrap_Struct(cgsl_vector_tau, 0, gsl_vector_free, tau);
       return rb_ary_new3(2, mdecomp, vtau);
     } else {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+      rb_obj_reveal(argv[itmp], cgsl_vector_tau);
+#else
       RBASIC(argv[itmp])->klass = cgsl_vector_tau;
+#endif
       return mdecomp;
     }
     break;
@@ -740,7 +756,11 @@ static VALUE rb_gsl_linalg_QR_LQ_decompo
    if (argc == itmp) {
       return Data_Wrap_Struct(cgsl_vector_tau, 0, gsl_vector_free, tau);
     } else {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+      rb_obj_reveal(argv[itmp], cgsl_vector_tau);
+#else
       RBASIC(argv[itmp])->klass = cgsl_vector_tau;
+#endif
       return INT2FIX(status);
     }
     break;
@@ -1628,14 +1648,22 @@ static VALUE rb_gsl_linalg_QRLQPT_decomp
   norm = gsl_vector_alloc(size0);
   switch (flag) {
   case LINALG_QRPT:
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(vA, cgsl_matrix_QRPT);
+#else
     RBASIC(vA)->klass = cgsl_matrix_QRPT;
+#endif
     vtau = Data_Wrap_Struct(cgsl_vector_tau, 0, gsl_vector_free, tau);
     vp = Data_Wrap_Struct(cgsl_permutation, 0, gsl_permutation_free, p);
     gsl_linalg_QRPT_decomp(A, tau, p, &signum, norm);
     break;
 #ifdef GSL_1_6_LATER
   case LINALG_PTLQ:
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(vA, cgsl_matrix_PTLQ);
+#else
     RBASIC(vA)->klass = cgsl_matrix_PTLQ;
+#endif
     vtau = Data_Wrap_Struct(cgsl_vector_tau, 0, gsl_vector_free, tau);
     vp = Data_Wrap_Struct(cgsl_permutation, 0, gsl_permutation_free, p);
     gsl_linalg_PTLQ_decomp(A, tau, p, &signum, norm);
