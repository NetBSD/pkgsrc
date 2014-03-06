$NetBSD: patch-InOut_winFLTK.c,v 1.1 2014/03/06 10:16:53 mrg Exp $

--- InOut/winFLTK.c.orig	2014-01-07 08:53:47.000000000 -0800
+++ InOut/winFLTK.c	2014-02-12 23:47:05.000000000 -0800
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
           csound->Message(csound, "graph init \n");
 
         }
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       }
 #endif
     }
