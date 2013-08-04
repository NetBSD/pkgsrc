$NetBSD: patch-ext_wavelet.c,v 1.1 2013/08/04 16:42:11 taca Exp $

Fix for gsl 1.6 and later; stop using deprecated API.

--- ext/wavelet.c.orig	2013-08-04 16:38:23.000000000 +0000
+++ ext/wavelet.c
@@ -152,10 +152,10 @@ static void rb_gsl_wavelet_define_const(
   rb_define_const(klass, "BSPLINE", INT2FIX(GSL_WAVELET_BSPLINE));
   rb_define_const(klass, "BSPLINE_CENTERED", INT2FIX(GSL_WAVELET_BSPLINE_CENTERED));
   /*****/
-  rb_define_const(klass, "FORWARD", INT2FIX(forward));
-  rb_define_const(klass, "Forward", INT2FIX(forward));
-  rb_define_const(klass, "BACKWARD", INT2FIX(backward));
-  rb_define_const(klass, "Backward", INT2FIX(backward));
+  rb_define_const(klass, "FORWARD", INT2FIX(gsl_wavelet_forward));
+  rb_define_const(klass, "Forward", INT2FIX(gsl_wavelet_forward));
+  rb_define_const(klass, "BACKWARD", INT2FIX(gsl_wavelet_backward));
+  rb_define_const(klass, "Backward", INT2FIX(gsl_wavelet_backward));
 }
 
 static VALUE rb_gsl_wavelet_name(VALUE ww)
@@ -191,7 +191,7 @@ static VALUE rb_gsl_wavelet_transform0(i
 {
   gsl_wavelet *w = NULL;
   gsl_vector *v = NULL, *vnew;
-  gsl_wavelet_direction dir = forward;
+  gsl_wavelet_direction dir = gsl_wavelet_forward;
   gsl_wavelet_workspace *work = NULL;
   int itmp, flag = 0;
   // local variable "status" declared and set, but never used
@@ -531,7 +531,7 @@ static VALUE rb_gsl_wavelet2d(int argc, 
 {
   gsl_wavelet *w = NULL;
   gsl_matrix *m = NULL, *mnew;
-  gsl_wavelet_direction dir = forward;
+  gsl_wavelet_direction dir = gsl_wavelet_forward;
   gsl_wavelet_workspace *work = NULL;
   VALUE ary, ret;
   int itmp, flag = 0;
