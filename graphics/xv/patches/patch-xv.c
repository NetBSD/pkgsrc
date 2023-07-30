$NetBSD: patch-xv.c,v 1.1 2023/07/30 07:55:45 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e

--- xv.c.orig	2023-07-30 04:38:20.015663071 +0000
+++ xv.c
@@ -337,6 +337,10 @@ int main(argc, argv)
   pngW = (Window) NULL;  pngUp = 0;
 #endif
 
+#ifdef HAVE_WEBP
+  webpW = (Window) NULL; webpUp = 0;
+#endif
+
   pcdW = (Window) NULL;  pcdUp = 0;
 
 #ifdef HAVE_PIC2
@@ -980,6 +984,11 @@ int main(argc, argv)
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
@@ -1870,6 +1879,9 @@ static void cmdSyntax()
 #ifdef HAVE_PNG
   VersionInfoPNG();
 #endif
+#ifdef HAVE_WEBP
+  VersionInfoWEBP();
+#endif
   /* pbm/pgm/ppm support is native, not via pbmplus/netpbm libraries */
   fprintf(stderr, "\n");
 
@@ -3121,6 +3133,15 @@ int ReadFileType(fname)
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
@@ -3258,6 +3279,10 @@ int ReadPicFile(fname, ftype, pinfo, qui
   case RFT_PNG:     rv = LoadPNG   (fname, pinfo);         break;
 #endif
 
+#ifdef HAVE_WEBP
+  case RFT_WEBP:    rv = LoadWEBP  (fname, pinfo);         break;
+#endif
+
 #ifdef HAVE_PDS
   case RFT_PDSVICAR: rv = LoadPDS  (fname, pinfo);         break;
 #endif
