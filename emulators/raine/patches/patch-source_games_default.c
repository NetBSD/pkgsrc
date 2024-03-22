$NetBSD: patch-source_games_default.c,v 1.1 2024/03/22 09:00:43 nia Exp $

Ensure the correct history.h is included.

--- source/games/default.c.orig	2024-03-22 08:26:12.307365827 +0000
+++ source/games/default.c
@@ -40,7 +40,7 @@
 #include "control_internal.h"
 #endif
 #include "bld.h"
-#include "history.h"
+#include "../history.h"
 #include "leds.h"
 #include "ips.h"
 #if GENS_SH2
