$NetBSD: patch-spunk_str.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/str.cc.orig	1996-12-01 11:23:50.000000000 +0000
+++ spunk/str.cc
@@ -31,6 +31,7 @@
 #include "stream.h"
 #include "streamid.h"
 
+#undef CS
 
 
 // Register class String
