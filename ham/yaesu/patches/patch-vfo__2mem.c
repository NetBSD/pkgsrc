$NetBSD: patch-vfo__2mem.c,v 1.1 2012/10/24 15:38:07 joerg Exp $

--- vfo_2mem.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ vfo_2mem.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-vfo_2mem(int fdSer) {
+void vfo_2mem(int fdSer) {
     int opcode, memory_number, hide_byte, tx_mode;
 
     rd_flags(fdSer);
