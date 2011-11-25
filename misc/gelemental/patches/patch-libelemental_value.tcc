$NetBSD: patch-libelemental_value.tcc,v 1.1 2011/11/25 22:09:13 joerg Exp $

--- libelemental/value.tcc.orig	2011-11-25 18:05:28.000000000 +0000
+++ libelemental/value.tcc
@@ -26,6 +26,8 @@
 #error "value.tcc must be included from value.hh."
 #endif
 
+#include <limits>
+
 namespace Elemental {
 
 
