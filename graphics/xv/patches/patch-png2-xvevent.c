$NetBSD: patch-png2-xvevent.c,v 1.1 1999/06/13 16:23:54 hubertf Exp $

This patch is based on
http://www.mit.edu/afs/athena/contrib/graphics/src/xv/patches/png/xvpng.diff
It was edited to fit into the NetBSD Packages Collection! - HF

---------------------------------------------------------------------------


--- xvevent.c.patched	Sun Jun 13 03:34:03 1999
+++ xvevent.c	Sun Jun 13 03:37:59 1999
@@ -154,7 +154,7 @@
      int    *donep;
 {
   static int wasInfoUp=0, wasCtrlUp=0, wasDirUp=0, wasGamUp=0, wasPsUp=0;
-  static int wasJpegUp=0, wasTiffUp=0;
+  static int wasJpegUp=0, wasTiffUp=0, wasPngUp=0;
   static int wasPcdUp=0;
 
   static int mainWKludge=0;  /* force first mainW expose after a mainW config
@@ -234,6 +234,10 @@
     if (TIFFCheckEvent(event)) break;   /* event has been processed */
 #endif
 
+#ifdef HAVE_PNG
+    if (PNGCheckEvent (event)) break;   /* event has been processed */
+#endif
+
     if (PCDCheckEvent(event)) break;    /* event has been processed */
 
     if (GamCheckEvent (event)) break;   /* event has been processed */
@@ -362,6 +366,10 @@
       else if (client_event->window == tiffW) TIFFDialog(0);
 #endif
 
+#ifdef HAVE_PNG
+      else if (client_event->window == pngW)  PNGDialog(0);
+#endif
+
       else if (client_event->window == pcdW) PCDDialog(0);
 
       else if (client_event->window == mainW) Quit(0);
@@ -544,6 +552,10 @@
 	if (wasTiffUp) { TIFFDialog(wasTiffUp);  wasTiffUp=0; }
 #endif
 
+#ifdef HAVE_PNG
+        if (wasPngUp)  { PNGDialog(wasJpegUp);   wasPngUp=0; }
+#endif
+
       if (wasPcdUp)  { PCDDialog(wasPcdUp);    wasPcdUp=0; }
  
       }
@@ -585,6 +597,10 @@
 	  if (tiffUp) { wasTiffUp = tiffUp;  TIFFDialog(0); }
 #endif
 
+#ifdef HAVE_PNG
+          if (pngUp)  { wasPngUp  = pngUp;   PNGDialog(0); }
+#endif
+
         if (pcdUp) { wasPcdUp = pcdUp;  PCDDialog(0); }
 
 	}
@@ -1158,6 +1174,10 @@
     if (TIFFCheckEvent(event)) break;
 #endif
     
+#ifdef HAVE_PNG
+     if (PNGCheckEvent (event)) break;
+#endif
+
     if (PCDCheckEvent(event)) break;
 
     if (GamCheckEvent (event)) break;
@@ -1379,6 +1399,10 @@
     if (TIFFCheckEvent(event)) break;
 #endif
 
+#ifdef HAVE_PNG
+    if (PNGCheckEvent (event)) break;
+#endif
+
     if (PCDCheckEvent(event)) break;
 
     if (GamCheckEvent (event)) break;
@@ -2385,6 +2409,10 @@
 
 #ifdef HAVE_TIFF
   if (tiffUp) TIFFDialog(0);  /* close tiff window */
+#endif
+
+#ifdef HAVE_PNG
+  if (pngUp) PNGDialog(0);    /* close png window */
 #endif
 
   if (pcdUp) PCDDialog(0);    /* close pcd window */
