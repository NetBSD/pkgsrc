$NetBSD: patch-iodev_soundosx.cc,v 1.1 2011/03/02 15:43:12 ryoon Exp $

--- iodev/soundosx.cc.orig	2011-02-14 21:14:20.000000000 +0000
+++ iodev/soundosx.cc
@@ -21,7 +21,7 @@
 // This file (SOUNDOSX.CC) written and donated by Brian Huffman
 
 #ifdef PARANOID
-#include <MacTypes.h>
+#include <CoreServices/CoreServices.h>
 #endif
 
 #include "iodev.h"
