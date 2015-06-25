$NetBSD: patch-object__handler.hc,v 1.1 2015/06/25 06:22:11 dholland Exp $

Cast sqrt argument to double to placate the Solaris compiler.

--- object_handler.hc~	2015-06-25 06:13:03.000000000 +0000
+++ object_handler.hc
@@ -36,7 +36,7 @@ double dist (int x1, int y1, int x2, int
   {int xx = x1 - x2;
    int yy = y1 - y2;
 
-   return sqrt (xx * xx + yy * yy);
+   return sqrt ((double)(xx * xx + yy * yy));
   }
 
 int stepdist (int x1, int y1, int x2, int y2)
