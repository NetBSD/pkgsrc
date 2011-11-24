$NetBSD: patch-src_util.cxx,v 1.1 2011/11/24 14:14:58 joerg Exp $

--- src/util.cxx.orig	2011-11-24 00:13:51.000000000 +0000
+++ src/util.cxx
@@ -25,6 +25,7 @@
 #endif
 
 #include <cerrno>
+#include <cstring>
 #include <new>
 #include <sstream>
 
