$NetBSD: patch-InOut_winFLTK.c,v 1.3 2014/08/06 06:17:07 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- InOut/winFLTK.c.orig	2014-05-04 04:49:41.000000000 -0700
+++ InOut/winFLTK.c	2014-08-04 22:18:13.000000000 -0700
@@ -29,7 +29,7 @@
 #include <stdio.h>
 #include "cwindow.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <X11/Xlib.h>
 #endif
 
@@ -83,7 +83,7 @@
     fltkFlags = getFLTKFlagsPtr(csound);
     if (((*fltkFlags) & 2) == 0 &&
         !(oparms.graphsoff || oparms.postscript)) {
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       Display *dpy = XOpenDisplay(NULL);
       if (dpy != NULL) {
         XCloseDisplay(dpy);
@@ -104,7 +104,7 @@
           csound->Message(csound, "graph init... \n");
 
         }
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       }
 #endif
     }
