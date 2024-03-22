$NetBSD: patch-source_neocd_neocd.c,v 1.1 2024/03/22 09:00:43 nia Exp $

Ensure the correct history.h is included.

--- source/neocd/neocd.c.orig	2024-03-22 08:07:00.627106993 +0000
+++ source/neocd/neocd.c
@@ -29,7 +29,7 @@
 #include "cache.h"
 #include "default.h"
 #include "hiscore.h"
-#include "history.h"
+#include "../history.h"
 #include "display.h"
 #ifdef RAINE_DEBUG
 #include "gui.h"
