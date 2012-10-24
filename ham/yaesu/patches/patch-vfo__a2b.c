$NetBSD: patch-vfo__a2b.c,v 1.1 2012/10/24 15:38:07 joerg Exp $

--- vfo_a2b.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ vfo_a2b.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-vfo_a2b(int fdSer) {
+void vfo_a2b(int fdSer) {
    int opcode, tx_mode;
 
     rd_flags(fdSer);
