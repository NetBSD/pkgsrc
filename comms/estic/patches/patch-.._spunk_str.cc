$NetBSD: patch-.._spunk_str.cc,v 1.1 2012/02/16 16:47:58 hans Exp $

--- ../spunk/str.cc.orig	1996-12-01 11:23:50.000000000 +0100
+++ ../spunk/str.cc	2012-01-25 18:54:36.312130772 +0100
@@ -31,6 +31,7 @@
 #include "stream.h"
 #include "streamid.h"
 
+#undef CS
 
 
 // Register class String
