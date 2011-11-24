$NetBSD: patch-src_fusepod__util.h,v 1.1 2011/11/24 14:10:37 joerg Exp $

--- src/fusepod_util.h.orig	2011-11-24 00:19:43.000000000 +0000
+++ src/fusepod_util.h
@@ -17,6 +17,7 @@
 
 #include <vector>
 #include <string>
+#include <strings.h>
 
 using std::string;
 using std::vector;
