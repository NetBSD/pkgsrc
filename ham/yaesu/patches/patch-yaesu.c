$NetBSD: patch-yaesu.c,v 1.1 2012/10/24 15:38:07 joerg Exp $

--- yaesu.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ yaesu.c
@@ -1,6 +1,5 @@
-extern main();
-extern float freq_to_change_to;
-extern int yaesu_return;
+#include "yaesu.h"
+
 int aux_comeback;
 
 void yaesu(int fdSer) {
