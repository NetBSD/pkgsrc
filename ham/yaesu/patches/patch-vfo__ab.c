$NetBSD: patch-vfo__ab.c,v 1.1 2012/10/24 15:38:07 joerg Exp $

--- vfo_ab.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ vfo_ab.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-vfo_ab(int fdSer) {
+void vfo_ab(int fdSer) {
     int opcode, vfo_choice, tx_mode;
 
     rd_flags(fdSer);
