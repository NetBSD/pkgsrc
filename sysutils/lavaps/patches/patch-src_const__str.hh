$NetBSD: patch-src_const__str.hh,v 1.1 2011/11/25 22:18:54 joerg Exp $

--- src/const_str.hh.orig	2011-11-25 19:27:49.000000000 +0000
+++ src/const_str.hh
@@ -24,6 +24,7 @@
 #ifndef lavaps_const_str_h
 #define lavaps_const_str_h
 
+#include <stdlib.h>
 #include <string.h>
 
 class const_str {
