$NetBSD: patch-src-resources.h,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/resources.h.orig	2010-10-16 21:03:30.000000000 +0000
+++ src/resources.h
@@ -83,5 +83,7 @@
 #define IDM_SID_INTERP       41200
 #define IDM_SID_RESAMP       41201
 
+#ifdef WIN32
 #define Button1 1000
+#endif
 #define ListBox1 40900
