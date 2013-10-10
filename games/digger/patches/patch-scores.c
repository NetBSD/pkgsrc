$NetBSD: patch-scores.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- scores.c.orig	2013-10-09 23:15:30.000000000 +0000
+++ scores.c
@@ -159,11 +159,12 @@ void writecurscore(int col)
 void drawscores(void)
 {
   writenum(scdat[0].score,0,0,6,3);
-  if (nplayers==2 || diggers==2)
+  if (nplayers==2 || diggers==2) {
     if (scdat[1].score<100000l)
       writenum(scdat[1].score,236,0,6,3);
     else
       writenum(scdat[1].score,248,0,6,3);
+  }
 }
 
 void addscore(int n,Sint4 score)
