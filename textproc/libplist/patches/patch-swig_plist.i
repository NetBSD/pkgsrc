$NetBSD: patch-swig_plist.i,v 1.1 2012/01/01 14:39:33 shattered Exp $

--- swig/plist.i.orig	2011-03-20 16:45:21.000000000 +0000
+++ swig/plist.i
@@ -34,7 +34,7 @@
 }
 
 %typemap(out) timeval {
-    struct tm* t = gmtime ( &$1.tv_sec );
+    struct tm* t = gmtime ( (time_t*)&$1.tv_sec );
     if (t)
     {
 	PyDateTime_IMPORT;
