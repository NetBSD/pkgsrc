$NetBSD: patch-xvsmooth.c,v 1.1 2025/04/19 23:14:24 tsutsui Exp $

- Pull fixes from https://gitlab.com/DavidGriffith/xv
 - https://gitlab.com/DavidGriffith/xv/-/commit/b91710b5
   > Fix off-by-one's resulting in dereferencing out-of-bound memory.
 - https://gitlab.com/DavidGriffith/xv/-/commit/72c80bff
   > Fix off-by-one in smoothing code and use better interpolation/rounding.

--- xvsmooth.c.orig	2025-04-19 20:44:26.706721543 +0000
+++ xvsmooth.c
@@ -254,7 +254,7 @@ int   is24, swide, shigh, dwide, dhigh;
   bperpix = (is24) ? 3 : 1;
 
   for (j=0; j<=swide; j++)
-    pixarr[j] = (j*dwide + (15*swide)/16) / swide;
+    pixarr[j] = ((2 * j + 1 ) * dwide) / ( 2 * swide);
 
   cptr = pic824;  cptr1 = cptr + swide * bperpix;
 
@@ -369,26 +369,12 @@ int   is24, swide, shigh, dwide, dhigh;
 
   lastline = linecnt = 0;
 
-  for (i=0, clptr=pic824; i<=shigh; i++, clptr+=swide*bperpix) {
+  for (i=0, clptr=pic824; i<shigh; i++, clptr+=swide*bperpix) {
     ProgressMeter(0, shigh, i, "Smooth");
     if ((i&15) == 0) WaitCursor();
 
     thisline = (i * dhigh + (15*shigh)/16) / shigh;
 
-    if (thisline != lastline) {  /* copy a line to pic24 */
-      for (j=0; j<dwide; j++) {
-	*pic24++ = lbufR[j] / linecnt;
-	*pic24++ = lbufG[j] / linecnt;
-	*pic24++ = lbufB[j] / linecnt;
-      }
-
-      xvbzero( (char *) lbufR, dwide * sizeof(int));  /* clear out line bufs */
-      xvbzero( (char *) lbufG, dwide * sizeof(int));
-      xvbzero( (char *) lbufB, dwide * sizeof(int));
-      linecnt = 0;  lastline = thisline;
-    }
-
-
     for (j=0, cxptr=cxarr; j<dwide; j++, cxptr++) {
       cptr  = clptr + *cxptr * bperpix;
       if (*cxptr < swide-1) cptr1 = cptr + 1*bperpix;
@@ -407,6 +393,21 @@ int   is24, swide, shigh, dwide, dhigh;
     }
 
     linecnt++;
+
+    thisline = ((2 * i + 3) * dhigh) / (2 * shigh);
+
+    if (thisline != lastline) {  /* copy a line to pic24 */
+      for (j=0; j<dwide; j++) {
+       *pic24++ = lbufR[j] / linecnt;
+       *pic24++ = lbufG[j] / linecnt;
+       *pic24++ = lbufB[j] / linecnt;
+      }
+
+      xvbzero( (char *) lbufR, dwide * sizeof(int));  /* clear out line bufs */
+      xvbzero( (char *) lbufG, dwide * sizeof(int));
+      xvbzero( (char *) lbufB, dwide * sizeof(int));
+      linecnt = 0;  lastline = thisline;
+    }
   }
 
 
@@ -463,16 +464,16 @@ int   is24, swide, shigh, dwide, dhigh;
   bperpix = (is24) ? 3 : 1;
 
   for (j=0; j<=swide; j++)
-    pixarr[j] = (j*dwide + (15*swide)/16) / swide;
+    pixarr[j] = ((2 * j + 1) * dwide) / (2 * swide);
 
   lastline = linecnt = pixR = pixG = pixB = 0;
   cptr = pic824;
 
-  for (i=0; i<=shigh; i++) {
+  for (i=0; i<shigh; i++) {
     ProgressMeter(0, shigh, i, "Smooth");
     if ((i&15) == 0) WaitCursor();
 
-    thisline = (i * dhigh + (15*shigh)/16 ) / shigh;
+    thisline = ((2 * i + 1) * dhigh) / (2 * shigh);
 
     if ((thisline != lastline)) {      /* copy a line to pic24 */
       pixR = pixG = pixB = pixcnt = lastpix = 0;
