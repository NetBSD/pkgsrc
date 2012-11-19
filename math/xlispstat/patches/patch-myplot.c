$NetBSD: patch-myplot.c,v 1.1 2012/11/19 02:56:44 joerg Exp $

--- myplot.c.orig	2012-11-18 23:19:47.000000000 +0000
+++ myplot.c
@@ -41,7 +41,7 @@ static double NiceValue(x)
 	}
 }
 
-static SetNiceRange(xmin, xmax, ticks)
+static void SetNiceRange(xmin, xmax, ticks)
      double *xmin, *xmax;
      int *ticks;
 {
