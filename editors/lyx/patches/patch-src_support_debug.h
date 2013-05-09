$NetBSD: patch-src_support_debug.h,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- src/support/debug.h.orig	2013-05-09 11:37:52.000000000 +0000
+++ src/support/debug.h
@@ -19,17 +19,8 @@
 #define LYXDEBUG_H
 
 #include "support/strfwd.h"
-
-
-namespace std {
-
-class ios_base;
-
-template<typename CharT, typename Traits> class basic_streambuf;
-typedef basic_streambuf<char, char_traits<char> > streambuf;
-
-}
-
+#include <ios>
+#include <streambuf>
 
 namespace lyx {
 
