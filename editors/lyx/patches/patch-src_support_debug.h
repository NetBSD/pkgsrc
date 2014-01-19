$NetBSD: patch-src_support_debug.h,v 1.2 2014/01/19 14:04:39 rumko Exp $

--- src/support/debug.h.orig	2013-04-29 15:58:31.000000000 +0000
+++ src/support/debug.h
@@ -16,16 +16,8 @@
 #define LYXDEBUG_H
 
 #include "support/strfwd.h"
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
 
