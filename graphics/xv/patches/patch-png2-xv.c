$NetBSD: patch-png2-xv.c,v 1.1 1999/06/13 16:23:54 hubertf Exp $

This patch is based on
http://www.mit.edu/afs/athena/contrib/graphics/src/xv/patches/png/xvpng.diff
It was edited to fit into the NetBSD Packages Collection! - HF

---------------------------------------------------------------------------


--- xv.c.patched	Sun Jun 13 02:45:51 1999
+++ xv.c	Sun Jun 13 02:49:26 1999
@@ -279,6 +279,10 @@
 
   pcdW = (Window) NULL;  pcdUp = 0;
 
+#ifdef HAVE_PNG 
+  pngW = (Window) NULL;  pngUp = 0;
+#endif
+
   imap = ctrlmap = gmap = browmap = cmtmap = 0;
 
   ch_offx = ch_offy = p_offx = p_offy = 0;
@@ -786,6 +790,11 @@
   
   CreatePCDW();
   XSetTransientForHint(theDisp, pcdW, dirW);
+
+#ifdef HAVE_PNG
+  CreatePNGW();
+  XSetTransientForHint(theDisp, pngW, dirW);
+#endif
   
   LoadFishCursors();
   SetCursors(-1);
@@ -2649,6 +2658,11 @@
 	   (magicno[0]=='I' && magicno[1]=='I'))        rv = RFT_TIFF;
 #endif
 
+#ifdef HAVE_PNG
+  else if (magicno[0]==0x89 && magicno[1]=='P' &&
+           magicno[2]=='N'  && magicno[3]=='G')                  rv = RFT_PNG;
+#endif
+
 #ifdef HAVE_PDS
   else if (strncmp((char *) magicno,  "NJPL1I00", (size_t) 8)==0 ||
 	   strncmp((char *) magicno+2,"NJPL1I",   (size_t) 6)==0 ||
@@ -2740,6 +2754,10 @@
 
 #ifdef HAVE_TIFF
   case RFT_TIFF:    rv = LoadTIFF  (fname, pinfo);           break;
+#endif
+
+#ifdef HAVE_PNG
+  case RFT_PNG:     rv = LoadPNG   (fname, pinfo);         break;
 #endif
 
 #ifdef HAVE_PDS
