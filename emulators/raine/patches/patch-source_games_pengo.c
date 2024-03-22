$NetBSD: patch-source_games_pengo.c,v 1.1 2024/03/22 09:00:43 nia Exp $

Ensure the correct history.h is included.

--- source/games/pengo.c.orig	2024-01-24 09:14:16.000000000 +0000
+++ source/games/pengo.c
@@ -106,7 +106,7 @@ Issue confirmed, it happens also in the 
 #include "raine_cpuid.h"
 #include "emumain.h" // set_reset_function
 #include "savegame.h"
-#include "history.h"
+#include "../history.h"
 #include "hiscore.h"
 #include "blit.h"
 #ifdef SDL
