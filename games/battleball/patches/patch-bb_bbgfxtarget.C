$NetBSD: patch-bb_bbgfxtarget.C,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- bb/bbgfxtarget.C.orig	2011-11-25 15:16:51.000000000 +0000
+++ bb/bbgfxtarget.C
@@ -5,7 +5,7 @@
 
 #include <assert.h>
 #include <string.h>      // to get strlen
-#include <iostream.h>
+#include <iostream>
 #include <X11/Xlib.h>    // to get XEvent, XFontStruct
 
 #ifndef NO_OPENGL
@@ -16,6 +16,7 @@
 #include "bbgfxtarget.h"
 #include "xpanel3d.h"    // to get MINDIST
 
+using namespace std;
 
 #define DEFAULTWINWIDTH 512
 #define DEFAULTWINHEIGHT ((int)(DEFAULTWINWIDTH*0.6+6*14+2))
