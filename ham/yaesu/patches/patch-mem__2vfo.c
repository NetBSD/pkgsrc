$NetBSD: patch-mem__2vfo.c,v 1.1 2012/10/24 15:38:01 joerg Exp $

--- mem_2vfo.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ mem_2vfo.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-mem_2vfo(int fdSer) {
+void mem_2vfo(int fdSer) {
     int opcode, memory_number, bogus, tx_mode;
     bogus = 1;
 
