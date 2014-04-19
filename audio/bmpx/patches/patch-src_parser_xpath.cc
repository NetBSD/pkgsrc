$NetBSD: patch-src_parser_xpath.cc,v 1.1 2014/04/19 14:46:06 joerg Exp $

--- src/parser/xpath.cc.orig	2014-04-19 11:54:39.000000000 +0000
+++ src/parser/xpath.cc
@@ -11,6 +11,7 @@
 #include "xpath.hh"
 #include <algorithm> // for lexicographical_compare
 #include <cassert>
+#include <ostream>
 
 // implementation  -----------------------------------------------------------//
 
