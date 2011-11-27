$NetBSD: patch-src_objects_tank.cc,v 1.1 2011/11/27 19:40:50 joerg Exp $

--- src/objects/tank.cc.orig	2011-11-27 02:41:49.000000000 +0000
+++ src/objects/tank.cc
@@ -28,6 +28,7 @@
 
     thomas.nyberg@usa.net				jonas_b@bitsmart.com
 *****************************************************************************/
+#include <algorithm>
 #include <string.h>
 #include <stdlib.h>
 #include <allegro.h>
@@ -53,9 +54,9 @@ char *comments[] = {
 "samples/olvictor.wav"};
 
 
-#define __URK ((NUM_SKADA - 1) - (energy <? (MAX_ENERGY - 1)) / (MAX_ENERGY / NUM_SKADA))
+#define __URK ((NUM_SKADA - 1) - std::min(energy, (MAX_ENERGY - 1)) / (MAX_ENERGY / NUM_SKADA))
 
-#define IMAGE(x) ((x) + 3 * (__URK <? 3))
+#define IMAGE(x) ((x) + 3 * std::min(__URK, 3))
 #define FROMIMAGE(x) ((x) % 3)
 
 #define STATE_NONE		0
