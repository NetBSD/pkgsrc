$NetBSD: patch-flower_string-convert.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/string-convert.cc.orig	2013-06-16 18:39:57.000000000 +0000
+++ flower/string-convert.cc
@@ -165,7 +165,7 @@ String_convert::int2dec (int i, size_t l
     fill_char = '0';
 
   // ugh
-  string dec_string = to_string (i);
+  string dec_string = ::to_string (i);
 
   // ugh
   return to_string (fill_char, ssize_t (length_i - dec_string.length ())) + dec_string;
@@ -299,7 +299,7 @@ String_convert::pointer_string (void con
 string
 String_convert::precision_string (double x, int n)
 {
-  string format = "%." + to_string (max (0, n - 1)) + "e";
+  string format = "%." + ::to_string (max (0, n - 1)) + "e";
   string str = double_string (abs (x), format.c_str ());
 
   int exp = dec2int (str.substr (str.length () - 3));
