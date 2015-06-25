$NetBSD: patch-craft.hc,v 1.1 2015/06/25 06:22:11 dholland Exp $

Cast sqrt argument to double to placate the Solaris compiler.

--- craft.hc~	2015-06-25 06:13:03.000000000 +0000
+++ craft.hc
@@ -221,7 +221,7 @@ double pdist (int x1, int y1, int x2, in
   {int xx = x1 - x2;
    int yy = y1 - y2;
 
-   return sqrt (xx * xx + yy * yy);
+   return sqrt ((double)(xx * xx + yy * yy));
   }
 
 void init_speed (double factor)
