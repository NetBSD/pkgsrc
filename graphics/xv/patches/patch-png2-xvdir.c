$NetBSD: patch-png2-xvdir.c,v 1.1 1999/06/13 16:23:54 hubertf Exp $

This patch is based on
http://www.mit.edu/afs/athena/contrib/graphics/src/xv/patches/png/xvpng.diff
It was edited to fit into the NetBSD Packages Collection! - HF

---------------------------------------------------------------------------


--- xvdir.c.patched	Sun Jun 13 03:27:12 1999
+++ xvdir.c	Sun Jun 13 03:33:01 1999
@@ -62,6 +62,9 @@
 #ifdef HAVE_TIFF
 			       "TIFF",
 #endif
+#ifdef HAVE_PNG
+                               "PNG",
+#endif 
 			       "PostScript",
 			       "PBM/PGM/PPM (raw)",
 			       "PBM/PGM/PPM (ascii)",
@@ -1123,6 +1126,14 @@
   }
 #endif
 
+#ifdef HAVE_PNG
+  else if (fmt == F_PNG) {   /* PNG */
+    PNGSaveParams(fullname, col);
+    PNGDialog(1);                   /* open PNG Dialog box */
+    dbut[S_BOK].lit = 0;  BTRedraw(&dbut[S_BOK]);
+    return 0;                      /* always 'succeeds' */
+  }
+#endif
 
 
 
@@ -1181,6 +1192,7 @@
   case F_FITS:
     rv = WriteFITS  (fp, thepic, ptype, w, h, rp, gp, bp, nc, col, 
 		     picComments);    
+    break;
   case F_MAG:
     rv = WriteMAG   (fp, thepic, ptype, w, h, rp, gp, bp, nc, col, 
 		     picComments);    break;
@@ -1415,19 +1427,26 @@
       (strcmp(lowsuf,"eps" )==0) ||
       (strcmp(lowsuf,"rgb" )==0) ||
       (strcmp(lowsuf,"tga" )==0) ||
-      (strcmp(lowsuf,"xpm" )==0) ||
       (strcmp(lowsuf,"fits")==0) ||
       (strcmp(lowsuf,"fts" )==0) ||
+#ifdef HAVE_JPEG
       (strcmp(lowsuf,"jpg" )==0) ||
       (strcmp(lowsuf,"jpeg")==0) ||
       (strcmp(lowsuf,"jfif")==0) ||
+#endif
+#ifdef HAVE_TIFF
       (strcmp(lowsuf,"tif" )==0) ||
       (strcmp(lowsuf,"tiff")==0) ||
+#endif
+#ifdef HAVE_PNG
+      (strcmp(lowsuf,"png" )==0) ||
+#endif
+      (strcmp(lowsuf,"xpm" )==0) ||
       (strcmp(lowsuf,"mag" )==0) ||
       (strcmp(lowsuf,"pic" )==0) ||
       (strcmp(lowsuf,"mki" )==0) ||
       (strcmp(lowsuf,"pi"  )==0) ||
-      (strcmp(lowsuf,"p2"  )==0)){
+      (strcmp(lowsuf,"p2"  )==0)) {
 
     /* found one.  set lowsuf = to the new suffix, and tack on to filename */
 
@@ -1462,6 +1481,9 @@
 
 #ifdef HAVE_TIFF
     case F_TIFF:     strcpy(lowsuf,"tif");  break;
+#endif
+#ifdef HAVE_PNG
+    case F_PNG:      strcpy(lowsuf,"png");  break;
 #endif
     case F_MAG:      strcpy(lowsuf,"mag");  break;
     case F_PIC:      strcpy(lowsuf,"pic");  break;
