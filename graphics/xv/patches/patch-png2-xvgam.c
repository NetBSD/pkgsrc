$NetBSD: patch-png2-xvgam.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvgam.c.orig	Fri Jan 13 20:51:14 1995
+++ xvgam.c	Sun Nov 14 14:05:49 1999
@@ -265,11 +265,11 @@
   BTCreate(&gbut[G_BRNDCOL], cmapF,  5 + 66 + 67 + 2, 189, 66, BUTTH, 
 	   "Random", infofg, infobg, hicol, locol);
 
-  DCreate(&rhDial, cmapF, 5, 215, 66, 100,   0,360,180, 5, 
+  DCreate(&rhDial, cmapF, 5, 215, 66, 100,   0.0, 360.0, 180.0, 1.0, 5.0, 
 	  infofg, infobg, hicol, locol, "Hue", NULL);
-  DCreate(&gsDial, cmapF, 72, 215, 66, 100,  0,360,180, 5, 
+  DCreate(&gsDial, cmapF, 72, 215, 66, 100,  0.0, 360.0, 180.0, 1.0, 5.0, 
 	  infofg, infobg, hicol, locol, "Sat.", NULL);
-  DCreate(&bvDial, cmapF, 139, 215, 66, 100,   0,360,180, 5, 
+  DCreate(&bvDial, cmapF, 139, 215, 66, 100, 0.0, 360.0, 180.0, 1.0, 5.0, 
 	  infofg, infobg, hicol, locol, "Value", NULL);
 
   rhDial.drawobj = gsDial.drawobj = bvDial.drawobj = dragEditColor;
@@ -359,7 +359,7 @@
 
   srcHD.drawobj = dstHD.drawobj = whtHD.drawobj = dragHueDial;
 
-  DCreate(&satDial, hsvF, 100, 199, 100, 121, -100, 100, 0, 5, 
+  DCreate(&satDial, hsvF, 100, 199, 100, 121, -100.0, 100.0, 0.0, 1.0, 5.0, 
 	   infofg, infobg,hicol,locol, "Saturation", "%");
 
   hueRB = RBCreate(NULL, hsvF,  7, 153, "1", 
@@ -722,7 +722,7 @@
 
   if (whtHD.enabCB.val && whtHD.satval) hsvnonlinear++;
 
-  if (satDial.val != 0) hsvnonlinear++;
+  if (satDial.val != 0.0) hsvnonlinear++;
 
   /* check intensity graf */
   for (i=0; i<256 && intGraf.func[i]==i; i++);
@@ -1291,14 +1291,14 @@
     rgb2hsv(rcmap[editColor], gcmap[editColor], bcmap[editColor], &h, &s, &v);
     if (h<0) h = 0;
 
-    DSetVal(&rhDial, (int) h);
-    DSetVal(&gsDial, (int) (s*100));
-    DSetVal(&bvDial, (int) (v*100));
+    DSetVal(&rhDial, h);
+    DSetVal(&gsDial, s*100);
+    DSetVal(&bvDial, v*100);
   }
   else {
-    DSetVal(&rhDial, rcmap[editColor]);
-    DSetVal(&gsDial, gcmap[editColor]);
-    DSetVal(&bvDial, bcmap[editColor]);
+    DSetVal(&rhDial, (double)rcmap[editColor]);
+    DSetVal(&gsDial, (double)gcmap[editColor]);
+    DSetVal(&bvDial, (double)bcmap[editColor]);
   }
 }
   
@@ -1310,16 +1310,15 @@
 
   if (hsvmode) {
     int rv, gv, bv;
-    hsv2rgb((double) rhDial.val, ((double) gsDial.val) / 100.0, 
-	    ((double) bvDial.val) / 100.0, &rv, &gv, &bv);
+    hsv2rgb(rhDial.val, gsDial.val / 100.0, bvDial.val / 100.0, &rv, &gv, &bv);
     rcmap[editColor] = rv;
     gcmap[editColor] = gv;
     bcmap[editColor] = bv;
   }
   else {
-    rcmap[editColor] = rhDial.val;
-    gcmap[editColor] = gsDial.val;
-    bcmap[editColor] = bvDial.val;
+    rcmap[editColor] = (int)rhDial.val;
+    gcmap[editColor] = (int)gsDial.val;
+    bcmap[editColor] = (int)bvDial.val;
   }
 }
 
@@ -1561,9 +1560,9 @@
     gsDial.title = "Green";
     bvDial.title = "Blue";
 		   
-    DSetRange(&rhDial, 0, 255, rcmap[editColor], 16);
-    DSetRange(&gsDial, 0, 255, gcmap[editColor], 16);
-    DSetRange(&bvDial, 0, 255, bcmap[editColor], 16);
+    DSetRange(&rhDial, 0.0, 255.0, (double)rcmap[editColor], 1.0, 16.0);
+    DSetRange(&gsDial, 0.0, 255.0, (double)gcmap[editColor], 1.0, 16.0);
+    DSetRange(&bvDial, 0.0, 255.0, (double)bcmap[editColor], 1.0, 16.0);
 
     XClearWindow(theDisp, rhDial.win);    DRedraw(&rhDial);
     XClearWindow(theDisp, gsDial.win);    DRedraw(&gsDial);
@@ -1581,9 +1580,9 @@
 	    &h, &s, &v);
 
     if (h<0.0) h = 0.0;
-    DSetRange(&rhDial, 0, 360, (int) h, 5);
-    DSetRange(&gsDial, 0, 100, (int) (s*100), 5);
-    DSetRange(&bvDial, 0, 100, (int) (v*100), 5);
+    DSetRange(&rhDial, 0.0, 360.0,     h, 1.0, 5.0);
+    DSetRange(&gsDial, 0.0, 100.0, s*100, 1.0, 5.0);
+    DSetRange(&bvDial, 0.0, 100.0, v*100, 1.0, 5.0);
 
     XClearWindow(theDisp, rhDial.win);    DRedraw(&rhDial);
     XClearWindow(theDisp, gsDial.win);    DRedraw(&gsDial);
@@ -1891,7 +1890,7 @@
     }
 
     /* apply satDial value to s */
-    s = s + ((double) satDial.val) / 100.0;
+    s = s + satDial.val / 100.0;
     if (s<0.0) s = 0.0;
     if (s>1.0) s = 1.0;
 
@@ -2007,7 +2006,7 @@
 
   gs->hueRBnum = RBWhich(hueRB);
 
-  gs->satval = satDial.val;
+  gs->satval = (int)satDial.val;
   GetGrafState(&intGraf,&gs->istate);
   GetGrafState(&rGraf,  &gs->rstate);
   GetGrafState(&gGraf,  &gs->gstate);
@@ -2064,8 +2063,8 @@
     changed++;
   }
     
-  if (gs->satval != satDial.val) {
-    DSetVal(&satDial,gs->satval);
+  if (gs->satval != (int)satDial.val) {
+    DSetVal(&satDial,(double)gs->satval);
     changed++;
   }
 
@@ -3200,7 +3199,7 @@
 
   if (whtHD.enabCB.val && whtHD.satval) hsvmod++;
 
-  if (satDial.val != 0) hsvmod++;
+  if (satDial.val != 0.0) hsvmod++;
 
   /* check intensity graf */
   for (i=0; i<256; i++) {
@@ -3284,7 +3283,7 @@
       }
 
       /* apply satDial value to s */
-      s = s + satDial.val;
+      s = s + (int)satDial.val;
       if (s<  0) s =   0;
       if (s>100) s = 100;
 
