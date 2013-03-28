$NetBSD: patch-src_shell.cc,v 1.1 2013/03/28 21:43:05 joerg Exp $

--- src/shell.cc.orig	2013-03-28 12:01:36.000000000 +0000
+++ src/shell.cc
@@ -1288,7 +1288,6 @@ namespace Bmp
     static guint mpris_player_signals[LAST_SIGNAL] = { 0 };
   }
 
-  class PlayerShell::Player;
   struct PlayerClass
   {
     GObjectClass parent;
