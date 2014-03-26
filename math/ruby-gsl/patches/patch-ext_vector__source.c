$NetBSD: patch-ext_vector__source.c,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- ext/vector_source.c.orig	2014-03-25 15:47:30.000000000 +0000
+++ ext/vector_source.c
@@ -673,16 +673,36 @@ static VALUE FUNCTION(rb_gsl_vector,tran
 static VALUE FUNCTION(rb_gsl_vector,trans_bang)(VALUE obj)
 {
 #ifdef BASE_DOUBLE
-  if (CLASS_OF(obj) == cgsl_vector) RBASIC(obj)->klass = cgsl_vector_col;
-  else if (CLASS_OF(obj) == cgsl_vector_col) RBASIC(obj)->klass = cgsl_vector;
-  else {
+  if (CLASS_OF(obj) == cgsl_vector) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector_col);
+#else
+    RBASIC(obj)->klass = cgsl_vector_col;
+#endif
+  } else if (CLASS_OF(obj) == cgsl_vector_col) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector);
+#else
+    RBASIC(obj)->klass = cgsl_vector;
+#endif
+  } else {
     rb_raise(rb_eRuntimeError, "method trans! for %s is not permitted.",
 	     rb_class2name(CLASS_OF(obj)));
   }	
 #elif defined(BASE_INT)
-  if (CLASS_OF(obj) == cgsl_vector_int) RBASIC(obj)->klass = cgsl_vector_int_col;
-  else if (CLASS_OF(obj) == cgsl_vector_int_col) RBASIC(obj)->klass = cgsl_vector_int;
-  else {
+  if (CLASS_OF(obj) == cgsl_vector_int) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector_int_col);
+#else
+    RBASIC(obj)->klass = cgsl_vector_int_col;
+#endif
+  } else if (CLASS_OF(obj) == cgsl_vector_int_col) {
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+    rb_obj_reveal(obj, cgsl_vector_int);
+#else
+    RBASIC(obj)->klass = cgsl_vector_int;
+#endif
+  } else {
     rb_raise(rb_eRuntimeError, "method trans! for %s is not permitted.",
 	     rb_class2name(CLASS_OF(obj)));
   }
