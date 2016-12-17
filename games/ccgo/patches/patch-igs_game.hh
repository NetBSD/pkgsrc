$NetBSD: patch-igs_game.hh,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/game.hh.orig	2015-11-20 13:39:00.000000000 +0000
+++ igs/game.hh
@@ -11,7 +11,6 @@
 #define IGS_GAME_HH
 #include "player.hh"
 #include <string>
-#include <sigc++/object.h>
 namespace igs
 {
 	class Game :
