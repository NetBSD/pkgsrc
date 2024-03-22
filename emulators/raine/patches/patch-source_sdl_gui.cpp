$NetBSD: patch-source_sdl_gui.cpp,v 1.1 2024/03/22 09:00:43 nia Exp $

Missing header for chdir(2)/unlink(2).
Ensure the correct history.h is included.

--- source/sdl/gui.cpp.orig	2024-01-24 09:14:16.000000000 +0000
+++ source/sdl/gui.cpp
@@ -2,13 +2,14 @@
 #include <SDL_image.h>
 #include <time.h>
 #include <dirent.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include "display.h"
 #include "dejap.h"
 #include "games/games.h"
 #include "config.h"
 #include "hiscore.h"
-#include "history.h"
+#include "../history.h"
 #include "games/default.h"
 #include "video/res.h"
 #include "control.h"
