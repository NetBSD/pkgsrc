$NetBSD: patch-jdk_src_solaris_native_sun_awt_X11Color.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

Casting.

--- jdk/src/solaris/native/sun/awt/X11Color.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/sun/awt/X11Color.c
@@ -119,7 +119,7 @@ int getVirtCubeSize() {
         return LOOKUPSIZE;
     }
 
-    for (i = 0; i < MACHMAPSIZE; i++) {
+    for (i = 0; i < (int)MACHMAPSIZE; i++) {
         if (strcmp(name.machine, machinemap[i].machine) == 0) {
 #ifdef DEBUG
             if (debug_colormap) {
