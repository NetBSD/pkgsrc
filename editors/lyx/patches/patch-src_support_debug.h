$NetBSD: patch-src_support_debug.h,v 1.3 2015/01/10 18:13:22 rumko Exp $

--- src/support/debug.h.orig	2014-11-15 18:11:26.000000000 +0000
+++ src/support/debug.h
@@ -21,14 +21,8 @@
 // but ios_base has already been defined in strfwd
 // if compiling with it
 #ifndef  _LIBCPP_VERSION
-namespace std {
-
-class ios_base;
-
-template<typename CharT, typename Traits> class basic_streambuf;
-typedef basic_streambuf<char, char_traits<char> > streambuf;
-
-}
+#include <ios>
+#include <streambuf>
 #endif
 
 
