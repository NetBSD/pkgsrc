$NetBSD: patch-mainwin.c,v 1.1 2018/07/19 04:05:08 tpaul Exp $

Also include <X11/Xutil.h>, needed for XDestroyImage() and XPutPixel().

--- mainwin.c.orig	2004-10-02 19:24:33.000000000 +0000
+++ mainwin.c
@@ -1,4 +1,5 @@
 #include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <X11/keysym.h>
 #ifdef HAVE_LIMITS_H
 #include <limits.h>
