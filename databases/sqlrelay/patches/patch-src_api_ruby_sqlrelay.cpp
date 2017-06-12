$NetBSD: patch-src_api_ruby_sqlrelay.cpp,v 1.1 2017/06/12 17:06:18 taca Exp $

Fix for Ruby 2.4 and later.

--- src/api/ruby/sqlrelay.cpp.orig	2016-12-20 08:40:41.000000000 +0000
+++ src/api/ruby/sqlrelay.cpp
@@ -922,9 +922,11 @@ static VALUE sqlrcur_substitution(int ar
 	Data_Get_Struct(self,sqlrcursor,sqlrcur);
 	if (rb_obj_is_instance_of(value,rb_cString)==Qtrue) {
 		sqlrcur->substitution(STR2CSTR(variable),STR2CSTR(value));
-	} else if (rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
+	} else if (rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#ifndef RUBY_INTEGER_UNIFICATION
+		        rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
 			rb_obj_is_instance_of(value,rb_cFixnum)==Qtrue ||
-			rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#endif
 			rb_obj_is_instance_of(value,rb_cNumeric)==Qtrue) {
 		sqlrcur->substitution(STR2CSTR(variable),NUM2INT(value));
 	} else if (rb_obj_is_instance_of(value,rb_cFloat)==Qtrue) {
@@ -958,9 +960,12 @@ static VALUE sqlrcur_inputBind(int argc,
 	rb_scan_args(argc,argv,"22",&variable,&value,&precision,&scale);
 	Data_Get_Struct(self,sqlrcursor,sqlrcur);
 	if (rb_obj_is_instance_of(value,rb_cString)==Qtrue) {
-		if ((rb_obj_is_instance_of(precision,rb_cBignum)==Qtrue ||
+		if ((rb_obj_is_instance_of(precision,rb_cInteger)==Qtrue ||
+
+#ifndef RUBY_INTEGER_UNIFICATION
+		        rb_obj_is_instance_of(precision,rb_cBignum)==Qtrue ||
 			rb_obj_is_instance_of(precision,rb_cFixnum)==Qtrue ||
-			rb_obj_is_instance_of(precision,rb_cInteger)==Qtrue ||
+#endif
 			rb_obj_is_instance_of(precision,rb_cNumeric)==Qtrue) && 
 			NUM2INT(precision)>0) {
 			// in this case, the precision parameter is actually
@@ -970,9 +975,11 @@ static VALUE sqlrcur_inputBind(int argc,
 		} else {
 			sqlrcur->inputBind(STR2CSTR(variable),STR2CSTR(value));
 		}
-	} else if (rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
+	} else if (rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#ifndef RUBY_INTEGER_UNIFICATION
+		        rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
 			rb_obj_is_instance_of(value,rb_cFixnum)==Qtrue ||
-			rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#endif
 			rb_obj_is_instance_of(value,rb_cNumeric)==Qtrue) {
 		sqlrcur->inputBind(STR2CSTR(variable),NUM2INT(value));
 	} else if (rb_obj_is_instance_of(value,rb_cFloat)==Qtrue) {
@@ -1140,9 +1147,11 @@ static VALUE sqlrcur_substitutions(int a
 		if (rb_obj_is_instance_of(value,rb_cString)==Qtrue) {
 			sqlrcur->substitution(STR2CSTR(variable),
 						STR2CSTR(value));
-		} else if (rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
+		} else if (rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#ifndef RUBY_INTEGER_UNIFICATION
+			rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
 			rb_obj_is_instance_of(value,rb_cFixnum)==Qtrue ||
-			rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#endif
 			rb_obj_is_instance_of(value,rb_cNumeric)==Qtrue) {
 			sqlrcur->substitution(STR2CSTR(variable),
 						NUM2INT(value));
@@ -1197,9 +1206,11 @@ static VALUE sqlrcur_inputBinds(int argc
 		}
 		if (rb_obj_is_instance_of(value,rb_cString)==Qtrue) {
 			sqlrcur->inputBind(STR2CSTR(variable),STR2CSTR(value));
-		} else if (rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
+		} else if (rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#ifndef RUBY_INTEGER_UNIFICATION
+			rb_obj_is_instance_of(value,rb_cBignum)==Qtrue ||
 			rb_obj_is_instance_of(value,rb_cFixnum)==Qtrue ||
-			rb_obj_is_instance_of(value,rb_cInteger)==Qtrue ||
+#endif
 			rb_obj_is_instance_of(value,rb_cNumeric)==Qtrue) {
 			sqlrcur->inputBind(STR2CSTR(variable),NUM2INT(value));
 		} else if (rb_obj_is_instance_of(value,rb_cFloat)==Qtrue) {
