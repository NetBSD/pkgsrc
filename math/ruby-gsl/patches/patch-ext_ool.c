$NetBSD: patch-ext_ool.c,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- ext/ool.c.orig	2014-03-25 15:47:30.000000000 +0000
+++ ext/ool.c
@@ -770,7 +770,11 @@ static VALUE rb_ool_conmin_pgrad_paramet
 	VALUE ary;
 	ool_conmin_parameters_default(ool_conmin_minimizer_pgrad, (void*) &P);
 	ary = create_parameters_ary_pgrad(&P);
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR >= 1
+	rb_obj_reveal(ary, cool_conmin_pgrad_parameters);
+#else
 	RBASIC(ary)->klass = cool_conmin_pgrad_parameters;
+#endif
 	return ary;
 }
 
