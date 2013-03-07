$NetBSD: patch-mzrouter_mzDebug.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- mzrouter/mzDebug.c.orig	2013-03-02 22:18:25.000000000 +0000
+++ mzrouter/mzDebug.c
@@ -412,9 +412,8 @@ mzPrintRP(path)
 }
 
 /* mzPrintPathHead -- */
-int 
-mzPrintPathHead(path)
-    RoutePath *path;
+void 
+mzPrintPathHead(RoutePath *path)
 {
 
     if(path==NULL)
