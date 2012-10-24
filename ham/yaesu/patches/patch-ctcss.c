$NetBSD: patch-ctcss.c,v 1.1 2012/10/24 15:38:00 joerg Exp $

--- ctcss.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ ctcss.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-ctcss(int fdSer) {
+void ctcss(int fdSer) {
     int opcode, n, tx_mode;
     float ctcss_user_value;
     float ctcss_freq[34] = {67, 71.9, 77.0, 82.5, 88.5, 94.8, 100, 103.5, 107.2, 110.9, 114.8, 118.8, 123, 127.3, 131.8, 136.5, 141.3, 146.2, 151.4, 156.7, 162.2, 167.9, 173.8, 179.9, 186.2, 192.8, 203.5, 210.7, 218.1, 225.7, 233.6, 241.8, 250.3, 9}; 
