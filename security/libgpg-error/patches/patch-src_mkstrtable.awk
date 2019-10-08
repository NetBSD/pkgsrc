$NetBSD: patch-src_mkstrtable.awk,v 1.1 2019/10/08 06:36:13 triaxx Exp $

Prepare for Gawk 5.0.
Use pkg_namespace (instead of namespace).
Don't escape # in regexp.
https://github.com/gpg/libgpg-error/commit/7865041

--- src/mkstrtable.awk.orig	2013-03-15 19:24:25.000000000 +0000
+++ src/mkstrtable.awk
@@ -77,7 +77,7 @@
 #
 # The variable prefix can be used to prepend a string to each message.
 #
-# The variable namespace can be used to prepend a string to each
+# The variable pkg_namespace can be used to prepend a string to each
 # variable and macro name.
 
 BEGIN {
@@ -102,7 +102,7 @@ header {
       print "/* The purpose of this complex string table is to produce";
       print "   optimal code with a minimum of relocations.  */";
       print "";
-      print "static const char " namespace "msgstr[] = ";
+      print "static const char " pkg_namespace "msgstr[] = ";
       header = 0;
     }
   else
@@ -110,7 +110,7 @@ header {
 }
 
 !header {
-  sub (/\#.+/, "");
+  sub (/#.+/, "");
   sub (/[ 	]+$/, ""); # Strip trailing space and tab characters.
 
   if (/^$/)
@@ -150,7 +150,7 @@ END {
   else
     print "  gettext_noop (\"" last_msgstr "\");";
   print "";
-  print "static const int " namespace "msgidx[] =";
+  print "static const int " pkg_namespace "msgidx[] =";
   print "  {";
   for (i = 0; i < coded_msgs; i++)
     print "    " pos[i] ",";
@@ -158,7 +158,7 @@ END {
   print "  };";
   print "";
   print "static GPG_ERR_INLINE int";
-  print namespace "msgidxof (int code)";
+  print pkg_namespace "msgidxof (int code)";
   print "{";
   print "  return (0 ? 0";
 
