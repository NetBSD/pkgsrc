$NetBSD: patch-compiler_cpp_src_generate_t__rb__generator.cc,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- compiler/cpp/src/generate/t_rb_generator.cc.orig	2013-05-03 22:00:09.000000000 +0000
+++ compiler/cpp/src/generate/t_rb_generator.cc
@@ -321,7 +321,10 @@ void t_rb_generator::generate_enum(t_enu
   for(c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
     // Populate the hash
     int value = (*c_iter)->get_value();
-    first ? first = false : f_types_ << ", ";
+    if (first)
+      first = false;
+    else
+      f_types_ << ", ";
     f_types_ << value << " => \"" << capitalize((*c_iter)->get_name()) << "\"";
   }
   f_types_ << "}" << endl;
@@ -331,7 +334,10 @@ void t_rb_generator::generate_enum(t_enu
   first = true;
   for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
     // Populate the set
-    first ? first = false : f_types_ << ", ";
+    if (first)
+      first = false;
+    else
+      f_types_ << ", ";
     f_types_ << capitalize((*c_iter)->get_name());
   }
   f_types_ << "]).freeze" << endl;
