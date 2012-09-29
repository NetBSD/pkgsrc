$NetBSD: patch-swig_plist.i,v 1.2 2012/09/29 08:39:23 dholland Exp $

Fix build on platforms where tv_sec isn't time_t.

--- swig/plist.i.orig	2012-01-11 14:29:30.000000000 +0000
+++ swig/plist.i
@@ -35,7 +35,8 @@
 }
 
 %typemap(out) timeval {
-    struct tm* t = gmtime ( &$1.tv_sec );
+    time_t mytime = $1.tv_sec;
+    struct tm* t = gmtime ( &mytime );
     if (t)
     {
 	PyDateTime_IMPORT;
