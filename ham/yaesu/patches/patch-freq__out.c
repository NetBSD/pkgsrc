$NetBSD: patch-freq__out.c,v 1.1 2012/10/24 15:38:01 joerg Exp $

--- freq_out.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ freq_out.c
@@ -1,9 +1,6 @@
-extern main();
-extern float freq_to_change_to;
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-freq_out(int fdSer) {
+void freq_out(int fdSer) {
     int tens_MHz, ones_MHz, hundreds_kHz, tens_kHz, packed_oh_MkHz, ones_kHz;
     int packed_to_kHz, hundreds_Hz, tens_Hz, packed_ht_Hz, opcode, tx_mode;
 
