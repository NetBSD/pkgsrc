$NetBSD: patch-bb_player.C,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- bb/player.C.orig	2011-11-25 15:17:20.000000000 +0000
+++ bb/player.C
@@ -8,10 +8,11 @@
 #include <limits.h>      // to get INT_MAX, LONG_MAX
 #include <assert.h>
 #include <X11/keysym.h>  // to get XK_*
-#include <algo.h>        // ugh, this baby's big
+#include <algorithm>        // ugh, this baby's big
 #include "player.h"
 #include "xform.h"
 
+using namespace std;
 
 const coord
   COORD_MAX= LONG_MAX,
