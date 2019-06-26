$NetBSD: patch-src_player__window.c,v 1.2 2019/06/26 01:16:11 schmonz Exp $

#include <sys/types.h> for time_t definition on at least NetBSD.

--- src/player_window.c.orig	2014-05-10 14:48:57.000000000 +0000
+++ src/player_window.c
@@ -36,6 +36,7 @@
  * this file is used for the player control tab
  **********************************************************/
 
+#include <sys/types.h>
 #include <sys/timeb.h>
 
 #include "player_window.h"
