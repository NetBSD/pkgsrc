$NetBSD: patch-lily_keyword.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/keyword.cc.orig	2013-06-16 19:26:46.000000000 +0000
+++ lily/keyword.cc
@@ -2,6 +2,7 @@
   keyword.cc -- keywords and identifiers
 */
 
+#include "config.hh"
 #include "keyword.hh"
 
 #include <cstring>
