$NetBSD: patch-src_debug.h,v 1.1 2013/04/29 21:31:11 joerg Exp $

--- src/debug.h.orig	2013-04-29 19:01:20.000000000 +0000
+++ src/debug.h
@@ -22,6 +22,7 @@
 
 #include <string>
 #include <cstdio>
+#include <cstdlib>
 
 using std::string;
 
