$NetBSD: patch-xv.c,v 1.2 2025/04/19 23:14:24 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e
- pull XRandR support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/a84406cb
- pull flicker fix from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/f9d46bd9

--- xv.c.orig	2025-04-19 21:59:18.981323758 +0000
+++ xv.c
@@ -140,6 +140,9 @@ static int  argcmp                   PAR
                                            int, int, int *));
 static void add_filelist_to_namelist PARM((char *, char **, int *, int));
 
+#ifdef HAVE_XRR
+extern int RRevent_number, RRerror_number;
+#endif
 
 /* formerly local vars in main, made local to this module when
    parseResources() and parseCmdLine() were split out of main() */
@@ -169,6 +172,10 @@ int main(argc, argv)
 #ifdef TV_L10N
   int    j;
 #endif
+#ifdef HAVE_XRR
+  int major = -1, minor = -1;
+  int nScreens;
+#endif
   XColor ecdef;
   Window rootReturn, parentReturn, *children;
   unsigned int numChildren, rootDEEP;
@@ -337,6 +344,10 @@ int main(argc, argv)
   pngW = (Window) NULL;  pngUp = 0;
 #endif
 
+#ifdef HAVE_WEBP
+  webpW = (Window) NULL; webpUp = 0;
+#endif
+
   pcdW = (Window) NULL;  pcdUp = 0;
 
 #ifdef HAVE_PIC2
@@ -980,6 +991,11 @@ int main(argc, argv)
   XSetTransientForHint(theDisp, pngW, dirW);
 #endif
 
+#ifdef HAVE_WEBP
+  CreateWEBPW();
+  XSetTransientForHint(theDisp, webpW, dirW);
+#endif
+
 #ifdef HAVE_PCD
   CreatePCDW();
   XSetTransientForHint(theDisp, pcdW, dirW);
@@ -1030,8 +1046,26 @@ int main(argc, argv)
   /* make std colormap, maybe */
   ChangeCmapMode(colorMapMode, 0, 0);
 
+  /* Xrandr */
+#ifdef HAVE_XRR
+  if (!XRRQueryExtension(theDisp, &RRevent_number, &RRerror_number)) {
+    major = -1;
+  } else {
+    if (DEBUG) fprintf(stderr, "XRRQueryExtension: %d, %d\n", RRevent_number, RRerror_number);
 
+    if (!XRRQueryVersion(theDisp, &major, &minor)) {
+      if (DEBUG) fprintf(stderr, "XRRQueryVersion failed!\n");
+    } else {
+      if (DEBUG) fprintf(stderr, "XRRQueryVersion: %d, %d\n", major, minor);
+    }
 
+    nScreens = ScreenCount(theDisp);
+
+    for (i = 0; i < nScreens; i++) {
+      XRRSelectInput(theDisp, RootWindow(theDisp, i), RRScreenChangeNotifyMask);
+    }
+  }
+#endif
 
   /* Do The Thing... */
   mainLoop();
@@ -1182,10 +1216,10 @@ static void useOtherVisual(vinfo, best)
     XFlush(theDisp);
     XSync(theDisp, False);
 
-    xswa.background_pixel = 0;
+    xswa.background_pixmap = None;
     xswa.border_pixel     = 1;
     xswa.colormap         = theCmap;
-    xswamask = CWBackPixel | CWBorderPixel | CWColormap;
+    xswamask = CWBackPixmap | CWBorderPixel | CWColormap;
 
     win = XCreateWindow(theDisp, rootW, 0, 0, 100, 100, 2, (int) dispDEEP,
 			InputOutput, theVisual, xswamask, &xswa);
@@ -1870,6 +1904,9 @@ static void cmdSyntax()
 #ifdef HAVE_PNG
   VersionInfoPNG();
 #endif
+#ifdef HAVE_WEBP
+  VersionInfoWEBP();
+#endif
   /* pbm/pgm/ppm support is native, not via pbmplus/netpbm libraries */
   fprintf(stderr, "\n");
 
@@ -3121,6 +3158,15 @@ int ReadFileType(fname)
            magicno[2]=='N'  && magicno[3]=='G')               rv = RFT_PNG;
 #endif
 
+#ifdef HAVE_WEBP
+  else if (magicno[0]==0x52 && magicno[1]==0x49 &&
+          magicno[2]==0x46 && magicno[3]==0x46 &&
+          magicno[8]==0x57 && magicno[9]==0x45 &&
+          magicno[10]==0x42 && magicno[11]==0x50 &&
+          magicno[12]==0x56 && magicno[13]==0x50 &&
+          magicno[14]==0x38)                                 rv = RFT_WEBP;
+#endif
+
 #ifdef HAVE_PDS
   else if (strncmp((char *) magicno,  "NJPL1I00", (size_t) 8)==0 ||
 	   strncmp((char *) magicno+2,"NJPL1I",   (size_t) 6)==0 ||
@@ -3258,6 +3304,10 @@ int ReadPicFile(fname, ftype, pinfo, qui
   case RFT_PNG:     rv = LoadPNG   (fname, pinfo);         break;
 #endif
 
+#ifdef HAVE_WEBP
+  case RFT_WEBP:    rv = LoadWEBP  (fname, pinfo);         break;
+#endif
+
 #ifdef HAVE_PDS
   case RFT_PDSVICAR: rv = LoadPDS  (fname, pinfo);         break;
 #endif
@@ -3890,7 +3940,7 @@ static void createMainWindow(geom, name)
   hints.flags |= PSize | PMaxSize;
 
   xswa.bit_gravity      = StaticGravity;
-  xswa.background_pixel = bg;
+  xswa.background_pixmap  = None;
   xswa.border_pixel     = fg;
   xswa.colormap         = theCmap;
 
@@ -3905,7 +3955,8 @@ static void createMainWindow(geom, name)
      that windows, by default, have backing-store turned on, then the
      image window will, too */
 
-  xswamask = CWBackPixel | CWBorderPixel | CWColormap /* | CWBackingStore */;
+  /* CWBackPixel */
+  xswamask = CWBackPixmap | CWBorderPixel | CWColormap /* | CWBackingStore */;
   if (!clearonload) xswamask |= CWBitGravity;
 
   if (mainW) {
