$NetBSD: patch-aiStubs.c,v 1.1 2026/01/03 04:08:45 dholland Exp $

Use standard headers.

--- aiStubs.c~	1999-11-13 21:58:30.000000000 +0000
+++ aiStubs.c
@@ -20,6 +20,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "riskgame.h"
 #include "game.h"
