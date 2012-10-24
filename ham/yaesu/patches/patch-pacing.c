$NetBSD: patch-pacing.c,v 1.1 2012/10/24 15:38:03 joerg Exp $

--- pacing.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ pacing.c
@@ -1,10 +1,8 @@
-extern main();
-extern outport();
-
-#include <config.h>
+#include "yaesu.h"
+#include "config.h"
 
 /*  Make sure pacing is set for the most speed */
-pacing(int fdSer) {
+void pacing(int fdSer) {
     int opcode;
 
     opcode = 14;
