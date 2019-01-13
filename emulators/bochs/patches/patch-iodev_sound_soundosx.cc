$NetBSD: patch-iodev_sound_soundosx.cc,v 1.2 2019/01/13 11:59:38 ryoon Exp $

--- iodev/sound/soundosx.cc.orig	2017-03-14 18:21:05.000000000 +0000
+++ iodev/sound/soundosx.cc
@@ -26,7 +26,7 @@
 #define BX_PLUGGABLE
 
 #ifdef PARANOID
-#include <MacTypes.h>
+#include <CoreServices/CoreServices.h>
 #endif
 
 #include "iodev.h"
