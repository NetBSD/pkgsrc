$NetBSD: patch-repeater.c,v 1.1 2012/10/24 15:38:04 joerg Exp $

--- repeater.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ repeater.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-repeater_simplex(int fdSer) {
+void repeater_simplex(int fdSer) {
    int opcode, rptr_simplex, fm_byte, tx_mode;
 
     rd_flags(fdSer);
