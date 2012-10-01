$NetBSD: patch-iodev_sound_soundosx.cc,v 1.1 2012/10/01 13:40:48 ryoon Exp $

--- iodev/sound/soundosx.cc.orig	2012-09-02 11:30:10.000000000 +0000
+++ iodev/sound/soundosx.cc
@@ -21,7 +21,7 @@
 // This file (SOUNDOSX.CC) written and donated by Brian Huffman
 
 #ifdef PARANOID
-#include <MacTypes.h>
+#include <CoreServices/CoreServices.h>
 #endif
 
 #include "iodev.h"
