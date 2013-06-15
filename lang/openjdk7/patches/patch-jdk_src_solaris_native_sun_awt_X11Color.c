$NetBSD: patch-jdk_src_solaris_native_sun_awt_X11Color.c,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Casting.

--- jdk/src/solaris/native/sun/awt/X11Color.c.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/src/solaris/native/sun/awt/X11Color.c
@@ -119,7 +119,7 @@ int getVirtCubeSize() {
         return LOOKUPSIZE;
     }
 
-    for (i = 0; i < MACHMAPSIZE; i++) {
+    for (i = 0; i < (int)MACHMAPSIZE; i++) {
         if (strcmp(name.machine, machinemap[i].machine) == 0) {
 #ifdef DEBUG
             if (debug_colormap) {
