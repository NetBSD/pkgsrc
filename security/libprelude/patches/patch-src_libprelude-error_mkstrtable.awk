$NetBSD: patch-src_libprelude-error_mkstrtable.awk,v 1.1 2019/12/20 22:11:02 gutteridge Exp $

Rename the awk variable "namespace" to "name_space", since the former
is now a reserved word with GNU awk 5.0.

--- src/libprelude-error/mkstrtable.awk.orig	2009-05-12 07:49:42.000000000 +0000
+++ src/libprelude-error/mkstrtable.awk
@@ -77,7 +77,7 @@
 #
 # The variable prefix can be used to prepend a string to each message.
 #
-# The variable namespace can be used to prepend a string to each
+# The variable name_space can be used to prepend a string to each
 # variable and macro name.
 
 BEGIN {
@@ -102,7 +102,7 @@ header {
       print "/* The purpose of this complex string table is to produce";
       print "   optimal code with a minimum of relocations.  */";
       print "";
-      print "static const char " namespace "msgstr[] = ";
+      print "static const char " name_space "msgstr[] = ";
       header = 0;
     }
   else
@@ -150,14 +150,14 @@ END {
   else
     print "  gettext_noop (\"" prefix last_msgstr "\");";
   print "";
-  print "static const int " namespace "msgidx[] =";
+  print "static const int " name_space "msgidx[] =";
   print "  {";
   for (i = 0; i < coded_msgs; i++)
     print "    " pos[i] ",";
   print "    " pos[coded_msgs];
   print "  };";
   print "";
-  print "#define " namespace "msgidxof(code) (0 ? -1 \\";
+  print "#define " name_space "msgidxof(code) (0 ? -1 \\";
 
 # Gather the ranges.
   skip = code[0];
