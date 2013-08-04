$NetBSD: patch-ext_fft.c,v 1.1 2013/08/04 16:42:11 taca Exp $

Fix for gsl 1.6 and later; stop using deprecated API.

--- ext/fft.c.orig	2013-08-04 16:38:23.000000000 +0000
+++ ext/fft.c
@@ -907,10 +907,10 @@ void Init_gsl_fft(VALUE module)
 
   /*****/
 
-  rb_define_const(mgsl_fft, "Forward", INT2FIX(forward));
-  rb_define_const(mgsl_fft, "FORWARD", INT2FIX(forward));
-  rb_define_const(mgsl_fft, "Backward", INT2FIX(backward));
-  rb_define_const(mgsl_fft, "BACKWARD", INT2FIX(backward));
+  rb_define_const(mgsl_fft, "Forward", INT2FIX(gsl_fft_forward));
+  rb_define_const(mgsl_fft, "FORWARD", INT2FIX(gsl_fft_forward));
+  rb_define_const(mgsl_fft, "Backward", INT2FIX(gsl_fft_backward));
+  rb_define_const(mgsl_fft, "BACKWARD", INT2FIX(gsl_fft_backward));
 
   /* Transforms for complex vectors */
   rb_define_method(cgsl_vector_complex, "radix2_forward", 
