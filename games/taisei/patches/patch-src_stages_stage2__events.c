$NetBSD: patch-src_stages_stage2__events.c,v 1.1 2019/10/01 14:25:08 nia Exp $

Include math.h for copysign.

--- src/stages/stage2_events.c.orig	2019-09-29 03:54:57.000000000 +0000
+++ src/stages/stage2_events.c
@@ -7,11 +7,11 @@
  */
 
 #include "taisei.h"
-
 #include "stage2_events.h"
 #include "global.h"
 #include "stage.h"
 #include "enemy.h"
+#include <math.h>
 
 static Dialog *stage2_dialog_pre_boss(void) {
 	PlayerMode *pm = global.plr.mode;
