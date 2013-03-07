$NetBSD: patch-mzrouter_mzSearch.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- mzrouter/mzSearch.c.orig	2013-03-02 22:18:40.000000000 +0000
+++ mzrouter/mzSearch.c
@@ -154,6 +154,8 @@ extern void mzBloomInit();
 extern void mzMakeStatReport();
 extern void mzExtendPath(RoutePath *);
 
+void  mzPrintPathHead(RoutePath *path);
+
 
 /*
  * ----------------------------------------------------------------------------
