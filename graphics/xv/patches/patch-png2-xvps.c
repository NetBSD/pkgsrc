$NetBSD: patch-png2-xvps.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvps.c.orig	Thu Dec 22 23:34:42 1994
+++ xvps.c	Sun Nov 14 14:05:49 1999
@@ -139,9 +139,9 @@
   CBCreate(&encapsCB, psW, 240, 7, "preview", infofg, infobg, hicol, locol);
   CBCreate(&pscompCB, psW, 331, 7, "compress", infofg, infobg, hicol, locol);
 
-  DCreate(&xsDial, psW, 240, 30, 80, 100, 10, 800, 100, 5, 
+  DCreate(&xsDial, psW, 240, 30, 80, 100, 10.0, 800.0, 100.0, 0.5, 5.0, 
 	  infofg, infobg, hicol, locol, "Width", "%");
-  DCreate(&ysDial, psW, 331, 30, 80, 100, 10, 800, 100, 5, 
+  DCreate(&ysDial, psW, 331, 30, 80, 100, 10.0, 800.0, 100.0, 0.5, 5.0, 
 	  infofg, infobg, hicol, locol, "Height", "%");
   xsDial.drawobj = changedScale;
   ysDial.drawobj = changedScale;
@@ -236,10 +236,10 @@
 
   if (rd_int("psres")) {             /* xv.psres:  default paper resolution */
     if (def_int >= 10 && def_int <= 720) {
-      int i = (int) ((PIX2INCH * 100) / def_int);
+      double v = (PIX2INCH * 100) / def_int;
 
-      DSetVal(&xsDial, i);
-      DSetVal(&ysDial, i);
+      DSetVal(&xsDial, v);
+      DSetVal(&ysDial, v);
     }
   }
 
@@ -836,7 +836,7 @@
   if (scx < scy) { sz_iny = h * scx; }
             else { sz_inx = w * scy; }
 
-  DSetVal(&xsDial, (int) ((100 * (sz_inx * PIX2INCH) / w) + .5));
+  DSetVal(&xsDial, 100 * (sz_inx * PIX2INCH) / w);
   DSetVal(&ysDial, xsDial.val);
 
   sz_inx = (double) w / PIX2INCH * (xsDial.val / 100.0);  
