$NetBSD: patch-png2-xvjpeg.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvjpeg.c.orig	Sun Nov 14 14:05:46 1999
+++ xvjpeg.c	Sun Nov 14 14:05:49 1999
@@ -87,10 +87,10 @@
   
   XSelectInput(theDisp, jpegW, ExposureMask | ButtonPressMask | KeyPressMask);
   
-  DCreate(&qDial, jpegW, 10, 10, 80, 100, 1, 100, 75, 5, 
+  DCreate(&qDial, jpegW, 10, 10, 80, 100, 1.0, 100.0, 75.0, 1.0, 5.0, 
 	  infofg, infobg, hicol, locol, "Quality", "%");
   
-  DCreate(&smDial, jpegW, 120, 10, 80, 100, 0, 100, 0, 5, 
+  DCreate(&smDial, jpegW, 120, 10, 80, 100, 0.0, 100.0, 0.0, 1.0, 5.0, 
 	  infofg, infobg, hicol, locol, "Smoothing", "%");
   
   BTCreate(&jbut[J_BOK], jpegW, JWIDE-180-1, JHIGH-10-BUTTH-1, 80, BUTTH, 
@@ -759,8 +759,8 @@
 
 
   jpeg_set_defaults(&cinfo);
-  jpeg_set_quality(&cinfo, qDial.val, TRUE);
-  cinfo.smoothing_factor = smDial.val;
+  jpeg_set_quality(&cinfo, (int)qDial.val, TRUE);
+  cinfo.smoothing_factor = (int)smDial.val;
 
 
   jpeg_start_compress(&cinfo, TRUE);
@@ -769,7 +769,7 @@
   /*** COMMENT HANDLING ***/
 
   sprintf(xvcmt, "%sXV %s  Quality = %d, Smoothing = %d\n",
-	  CREATOR_STR, REVDATE, qDial.val, smDial.val);
+	  CREATOR_STR, REVDATE, (int)qDial.val, (int)smDial.val);
   
   if (picComments) {   /* append XV comment */
     char *sp, *sp1;  int done;
