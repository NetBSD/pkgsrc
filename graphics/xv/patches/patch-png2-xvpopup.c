$NetBSD: patch-png2-xvpopup.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvpopup.c.orig	Thu Jan 19 19:09:31 1995
+++ xvpopup.c	Sun Nov 14 14:05:49 1999
@@ -200,14 +200,14 @@
     
     if (!padHaveDooDads) {
       DCreate(&padWDial, popW, 16,      puhigh-16-100-1,75,100,
-	      1, 2048, pWIDE, 10,
+	      1.0, 2048.0, (double)pWIDE, 1.0, 10.0,
 	      infofg, infobg, hicol, locol, "Width", NULL);
       DCreate(&padHDial, popW, 16+1+75, puhigh-16-100-1,75,100,
-	      1, 2048, pHIGH, 10,
+	      1.0, 2048.0, (double)pHIGH, 1.0, 10.0,
 	      infofg, infobg, hicol, locol, "Height", NULL);
 
       DCreate(&padODial, popW, 16+1+75+75+9, puhigh-16-100-1,75,100,
-	      0, 100, 100, 10,
+	      0.0, 100.0, 100.0, 1.0, 10.0,
 	      infofg, infobg, hicol, locol, "Opaque", NULL);
 
       MBCreate(&padMthdMB, popW, 100-2+44, 10, 140, 19, NULL,
@@ -258,9 +258,9 @@
   else if (poptyp == ISPAD) {
     BTSetActive(&bts[0], (int) strlen(gsBuf));
     i = pWIDE * 3;  RANGE(i,2048,9999);  
-    DSetRange(&padWDial, 1, i, padWDial.val, 10);
+    DSetRange(&padWDial, 1.0, (double)i, padWDial.val, 1.0, 10.0);
     i = pHIGH * 3;  RANGE(i,2048,9999);  
-    DSetRange(&padHDial, 1, i, padHDial.val, 10);
+    DSetRange(&padHDial, 1.0, (double)i, padHDial.val, 1.0, 10.0);
 
     DSetActive(&padWDial, (padMode!=PAD_LOAD));  /* DSetRange activates dial */
     DSetActive(&padHDial, (padMode!=PAD_LOAD));
@@ -465,9 +465,9 @@
   changedGSBuf();      /* careful!  popW doesn't exist yet! */
 
   if (padHaveDooDads) { 
-    oldW = padWDial.val;  
-    oldH = padHDial.val;
-    oldO = padODial.val;
+    oldW = (int)padWDial.val;  
+    oldH = (int)padHDial.val;
+    oldO = (int)padODial.val;
   }
   else { oldW = pWIDE;  oldH = pHIGH;  oldO = 100; }
 
@@ -486,9 +486,9 @@
   }
 
   if (rv == 1) {   /* cancelled:  restore normal values */
-    DSetVal(&padWDial, oldW);
-    DSetVal(&padHDial, oldH);
-    DSetVal(&padODial, oldO);
+    DSetVal(&padWDial, (double)oldW);
+    DSetVal(&padHDial, (double)oldH);
+    DSetVal(&padODial, (double)oldO);
   }
 
   XUnmapWindow(theDisp, padWDial.win);
@@ -498,9 +498,9 @@
   /* load up return values */
   *pMode   = padMode;  
   *pStr    = padBuf;  
-  *pWide   = padWDial.val;
-  *pHigh   = padHDial.val;
-  *pOpaque = padODial.val;
+  *pWide   = (int)padWDial.val;
+  *pHigh   = (int)padHDial.val;
+  *pOpaque = (int)padODial.val;
   *pOmode  = padOMode;
 
   return rv;
@@ -972,8 +972,8 @@
   else if (popUp == ISPAD) {
     if (PTINRECT(x, y, padDButt.x, padDButt.y, padDButt.w, padDButt.h)) {
       if (BTTrack(&padDButt)) {
-	DSetVal(&padWDial, pWIDE);
-	DSetVal(&padHDial, pHIGH);
+	DSetVal(&padWDial, (double)pWIDE);
+	DSetVal(&padHDial, (double)pHIGH);
       }
     }
 
