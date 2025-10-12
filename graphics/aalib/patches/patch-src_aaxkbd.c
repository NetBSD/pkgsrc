$NetBSD: patch-src_aaxkbd.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aaxkbd.c.orig	2025-10-11 18:05:49.048397110 -0700
+++ src/aaxkbd.c	2025-10-11 18:07:01.573645712 -0700
@@ -5,6 +5,7 @@
 #include "config.h"
 #ifdef X11_KBDDRIVER
 #include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <X11/keysymdef.h>
 #include <X11/keysym.h>
 #include "aalib.h"
