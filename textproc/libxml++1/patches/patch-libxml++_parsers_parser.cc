$NetBSD: patch-libxml++_parsers_parser.cc,v 1.1 2011/08/14 18:54:53 wiz Exp $

Fix build with gcc-4.5.

--- libxml++/parsers/parser.cc.orig	2004-08-13 21:08:43.000000000 +0000
+++ libxml++/parsers/parser.cc
@@ -9,6 +9,7 @@
 #include <libxml/parser.h>
 
 #include <cstdarg> //For va_list.
+#include <memory> //For auto_ptr
 
 namespace xmlpp {
 
