$NetBSD: patch-clar.c,v 1.1 2012/10/24 15:38:00 joerg Exp $

--- clar.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ clar.c
@@ -1,11 +1,6 @@
-extern main();
-extern data_array[];
-extern data_return_param;
-extern flag_data_return[];
-extern memory_number;
-extern outport();
+#include "yaesu.h"
 
-clar(int fdSer) {
+void clar(int fdSer) {
    int opcode, vfo_a_b_op, vfo_b_op, mem_op, clar_finder, n, kHz_freq, Hz_freq;
    int up_down, dummy;
 
