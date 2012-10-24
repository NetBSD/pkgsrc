$NetBSD: patch-rptr__off.c,v 1.1 2012/10/24 15:38:04 joerg Exp $

--- rptr_off.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ rptr_off.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-rptr_off(int fdSer) {
+void rptr_off(int fdSer) {
     int hundreds_kHz, tens_kHz, ones_kHz, fm_byte, tx_mode;
     int packed_to_kHz, hundreds_Hz, tens_Hz, packed_ht_Hz, opcode;
     float freq;
