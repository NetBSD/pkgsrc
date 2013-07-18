$NetBSD: patch-vslib_vstring.h,v 1.1 2013/07/18 12:06:10 joerg Exp $

ISO C++ forbids default arguments on friend definitions that are not
declarations, so split them off.

--- vslib/vstring.h.orig	2013-07-17 14:05:27.000000000 +0000
+++ vslib/vstring.h
@@ -180,8 +180,8 @@
     friend String& str_cut      ( String& target, const char* charlist ); // does `CutR(charlist);CutL(charlist);'
     friend String& str_cut_spc  ( String& target ); // does `Cut(" ");'
 
-    friend String& str_pad  ( String& target, int len, char ch = ' ' );
-    friend String& str_comma( String& target, char delim = ',' );
+    friend String& str_pad  ( String& target, int len, char ch);
+    friend String& str_comma( String& target, char delim);
 
     // next 3 functions are safe! so if you get/set out f the string range!
     friend void str_set_ch( String& target, int pos, const char ch ); // sets `ch' char at position `pos'
@@ -209,6 +209,10 @@
 
   }; /* end of String class */
 
+
+  String& str_pad  ( String& target, int len, char ch = '=');
+  String& str_comma( String& target, char delim = '=');
+
 /****************************************************************************
 **
 ** STRING Functions (for class String)
