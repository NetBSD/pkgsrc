$NetBSD: patch-xvevent.c,v 1.2 2025/04/19 23:14:24 tsutsui Exp $

- add webp support using pkgsrc libwebp, from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e
 - a pasto of a comment is also fixed
- pull XRandR support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/a84406cb

--- xvevent.c.orig	2025-04-19 21:39:44.233828504 +0000
+++ xvevent.c
@@ -74,6 +74,10 @@ static void   annotatePic      PARM((voi
 static int    debkludge_offx;
 static int    debkludge_offy;
 
+#ifdef HAVE_XRR
+int RRevent_number = -1, RRerror_number = -1;
+#endif
+
 /****************/
 int EventLoop()
 /****************/
@@ -212,6 +216,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
   static int wasPngUp=0;
 #endif
+#ifdef HAVE_WEBP
+  static int wasWebpUp=0;
+#endif
 #ifdef HAVE_PCD
   static int wasPcdUp=0;
 #endif
@@ -221,6 +228,10 @@ int HandleEvent(event, donep)
 #ifdef HAVE_MGCSFX
   static int wasMgcSfxUp=0;
 #endif
+#ifdef HAVE_XRR
+  int screen;
+  XRRScreenChangeNotifyEvent *xrr_event;
+#endif
 
   static int mainWKludge=0;  /* force first mainW expose after a mainW config
 				to redraw all of mainW */
@@ -307,6 +318,10 @@ int HandleEvent(event, donep)
     if (PNGCheckEvent (event)) break;   /* event has been processed */
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent(event)) break;   /* event has been processed */
+#endif
+
     if (PCDCheckEvent(event)) break;    /* event has been processed */
 
 #ifdef HAVE_PIC2
@@ -462,6 +477,10 @@ int HandleEvent(event, donep)
       else if (client_event->window == pngW)  PNGDialog(0);
 #endif
 
+#ifdef HAVE_WEBP
+      else if (client_event->window == webpW)  WEBPDialog(0);
+#endif
+
       else if (client_event->window == pcdW)  PCDDialog(0);
 
 #ifdef HAVE_PIC2
@@ -664,6 +683,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
 	if (wasPngUp)  { PNGDialog(wasPngUp);    wasPngUp=0; }
 #endif
+#ifdef HAVE_WEBP
+       if (wasWebpUp) { WEBPDialog(wasWebpUp);  wasWebpUp=0; }
+#endif
 #ifdef HAVE_PCD
 	if (wasPcdUp)  { PCDDialog(wasPcdUp);    wasPcdUp=0; }
 #endif
@@ -716,6 +738,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
 	  if (pngUp)  { wasPngUp  = pngUp;   PNGDialog(0); }
 #endif
+#ifdef HAVE_WEBP
+         if (webpUp) { wasWebpUp = webpUp;  WEBPDialog(0); }
+#endif
 #ifdef HAVE_PCD
 	  if (pcdUp)  { wasPcdUp = pcdUp;    PCDDialog(0); }
 #endif
@@ -904,11 +929,24 @@ int HandleEvent(event, donep)
     }
     break;
 
-
-
   default: break;		/* ignore unexpected events */
   }  /* switch */
 
+#ifdef HAVE_XRR
+  if (event->type == RRevent_number + RRScreenChangeNotify) {
+    XRRUpdateConfiguration(event);
+    XSync (theDisp, False);
+    xrr_event = (XRRScreenChangeNotifyEvent *)event;
+
+    screen = XRRRootToScreen(theDisp, xrr_event->window);
+
+    dispWIDE = DisplayWidth(theDisp, screen);
+    dispHIGH = DisplayHeight(theDisp, screen);
+    maxWIDE = vrWIDE = dispWIDE;  maxHIGH = vrHIGH = dispHIGH;
+    HandleDispMode();
+  }
+#endif
+
   frominterrupt = 0;
   *donep = done;
   return(retval);
@@ -1338,6 +1376,10 @@ static void handleButtonEvent(event, don
     if (PNGCheckEvent (event)) break;
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent(event)) break;
+#endif
+
 #ifdef HAVE_PCD
     if (PCDCheckEvent (event)) break;	/* event has been processed */
 #endif
@@ -1621,6 +1663,10 @@ static void handleKeyEvent(event, donep,
     if (PNGCheckEvent (event)) break;
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent (event)) break;
+#endif
+
     if (PCDCheckEvent (event)) break;
 
 #ifdef HAVE_PIC2
@@ -2704,6 +2750,10 @@ static void onInterrupt(i)
   if (pngUp) PNGDialog(0);    /* close png window */
 #endif
 
+#ifdef HAVE_WEBP
+  if (webpUp) WEBPDialog(0);  /* close webp window */
+#endif
+
   if (pcdUp) PCDDialog(0);    /* close pcd window */
 
 #ifdef HAVE_PIC2
