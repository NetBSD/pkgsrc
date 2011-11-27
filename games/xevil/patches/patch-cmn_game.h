$NetBSD: patch-cmn_game.h,v 1.1 2011/11/27 19:43:33 joerg Exp $

--- cmn/game.h.orig	2011-11-27 02:22:18.000000000 +0000
+++ cmn/game.h
@@ -35,7 +35,7 @@
 extern "C" {
 #include <time.h>
 }
-#include <iostream.h>
+#include <iostream>
 #include "utils.h"
 #include "ui.h"
 #include "world.h"
