$NetBSD: patch-src_player__window.c,v 1.1 2019/06/25 21:25:24 schmonz Exp $

#include <sys/time.h> for time_t definition on at least NetBSD.

--- src/player_window.c.orig	2014-05-10 14:48:57.000000000 +0000
+++ src/player_window.c
@@ -36,6 +36,7 @@
  * this file is used for the player control tab
  **********************************************************/
 
+#include <sys/time.h>
 #include <sys/timeb.h>
 
 #include "player_window.h"
