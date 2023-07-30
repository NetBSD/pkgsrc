$NetBSD: patch-xvmisc.c,v 1.1 2023/07/30 07:55:45 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e

--- xvmisc.c.orig	2023-07-30 04:38:20.941982982 +0000
+++ xvmisc.c
@@ -549,6 +549,10 @@ void Quit(i)
     if (pngW)  XDestroyWindow(theDisp, pngW);
 #endif
 
+#ifdef HAVE_WEBP
+    if (webpW) XDestroyWindow(theDisp, webpW);
+#endif
+
 #ifdef HAVE_PCD
     if (pcdW)  XDestroyWindow(theDisp, pcdW);
 #endif
@@ -770,6 +774,10 @@ static void set_cursors(mainc, otherc)
   if (pngW)  XDefineCursor(theDisp, pngW, otherc);
 #endif
 
+#ifdef HAVE_WEBP
+  if (webpW)  XDefineCursor(theDisp, webpW, otherc);
+#endif
+
 #ifdef HAVE_PCD
   if (pcdW)  XDefineCursor(theDisp, pcdW, otherc);
 #endif
