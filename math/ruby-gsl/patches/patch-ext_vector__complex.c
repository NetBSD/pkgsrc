$NetBSD: patch-ext_vector__complex.c,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- ext/vector_complex.c.orig	2014-03-25 15:47:30.000000000 +0000
+++ ext/vector_complex.c
@@ -938,11 +938,19 @@ static VALUE rb_gsl_vector_complex_trans
 
 static VALUE rb_gsl_vector_complex_trans2(VALUE obj)
 {
-  if (CLASS_OF(obj) == cgsl_vector_complex) 
+  if (CLASS_OF(obj) == cgsl_vector_complex) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector_complex_col);
+#else
     RBASIC(obj)->klass = cgsl_vector_complex_col;
-  else if (CLASS_OF(obj) == cgsl_vector_complex_col) 
+#endif
+  } else if (CLASS_OF(obj) == cgsl_vector_complex_col) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector_complex);
+#else
     RBASIC(obj)->klass = cgsl_vector_complex;
-  else {
+#endif
+  } else {
     rb_raise(rb_eRuntimeError, "method trans! for %s is forbidden",
 	     rb_class2name(CLASS_OF(obj)));
   }
