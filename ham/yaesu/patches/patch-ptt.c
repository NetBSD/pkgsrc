$NetBSD: patch-ptt.c,v 1.1 2012/10/24 15:38:04 joerg Exp $

--- ptt.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ ptt.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-ptt(int fdSer) {
+void ptt(int fdSer) {
    int opcode, tx_status, cat_tx_status;
 
 /*  We have to make sure we can tx, we need to look for tx inhibitors */
