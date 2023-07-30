$NetBSD: patch-xvevent.c,v 1.1 2023/07/30 07:55:45 tsutsui Exp $

- add webp support using pkgsrc libwebp, from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e
 - a pasto of a comment is also fixed

--- xvevent.c.orig	2023-07-30 04:38:20.332206971 +0000
+++ xvevent.c
@@ -212,6 +212,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
   static int wasPngUp=0;
 #endif
+#ifdef HAVE_WEBP
+  static int wasWebpUp=0;
+#endif
 #ifdef HAVE_PCD
   static int wasPcdUp=0;
 #endif
@@ -307,6 +310,10 @@ int HandleEvent(event, donep)
     if (PNGCheckEvent (event)) break;   /* event has been processed */
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent(event)) break;   /* event has been processed */
+#endif
+
     if (PCDCheckEvent(event)) break;    /* event has been processed */
 
 #ifdef HAVE_PIC2
@@ -462,6 +469,10 @@ int HandleEvent(event, donep)
       else if (client_event->window == pngW)  PNGDialog(0);
 #endif
 
+#ifdef HAVE_WEBP
+      else if (client_event->window == webpW)  WEBPDialog(0);
+#endif
+
       else if (client_event->window == pcdW)  PCDDialog(0);
 
 #ifdef HAVE_PIC2
@@ -664,6 +675,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
 	if (wasPngUp)  { PNGDialog(wasPngUp);    wasPngUp=0; }
 #endif
+#ifdef HAVE_WEBP
+       if (wasWebpUp) { WEBPDialog(wasWebpUp);  wasWebpUp=0; }
+#endif
 #ifdef HAVE_PCD
 	if (wasPcdUp)  { PCDDialog(wasPcdUp);    wasPcdUp=0; }
 #endif
@@ -716,6 +730,9 @@ int HandleEvent(event, donep)
 #ifdef HAVE_PNG
 	  if (pngUp)  { wasPngUp  = pngUp;   PNGDialog(0); }
 #endif
+#ifdef HAVE_WEBP
+         if (webpUp) { wasWebpUp = webpUp;  WEBPDialog(0); }
+#endif
 #ifdef HAVE_PCD
 	  if (pcdUp)  { wasPcdUp = pcdUp;    PCDDialog(0); }
 #endif
@@ -1338,6 +1355,10 @@ static void handleButtonEvent(event, don
     if (PNGCheckEvent (event)) break;
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent(event)) break;
+#endif
+
 #ifdef HAVE_PCD
     if (PCDCheckEvent (event)) break;	/* event has been processed */
 #endif
@@ -1621,6 +1642,10 @@ static void handleKeyEvent(event, donep,
     if (PNGCheckEvent (event)) break;
 #endif
 
+#ifdef HAVE_WEBP
+    if (WEBPCheckEvent (event)) break;
+#endif
+
     if (PCDCheckEvent (event)) break;
 
 #ifdef HAVE_PIC2
@@ -2704,6 +2729,10 @@ static void onInterrupt(i)
   if (pngUp) PNGDialog(0);    /* close png window */
 #endif
 
+#ifdef HAVE_WEBP
+  if (webpUp) WEBPDialog(0);  /* close webp window */
+#endif
+
   if (pcdUp) PCDDialog(0);    /* close pcd window */
 
 #ifdef HAVE_PIC2
