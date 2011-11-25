$NetBSD: patch-src_player.h,v 1.1 2011/11/25 21:29:32 joerg Exp $

--- src/player.h.orig	2011-11-25 16:52:54.000000000 +0000
+++ src/player.h
@@ -22,6 +22,7 @@
 #ifndef H_ADPLUG_PLAYER
 #define H_ADPLUG_PLAYER
 
+#include <cstring>
 #include <string>
 
 #include "fprovide.h"
