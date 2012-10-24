$NetBSD: patch-wwv__find.c,v 1.1 2012/10/24 15:38:07 joerg Exp $

--- wwv_find.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ wwv_find.c
@@ -1,10 +1,8 @@
-extern main();
-extern float freq_to_change_to;
-extern flag_data_return[];
+#include "yaesu.h"
 
-wwv_find(int fdSer) {
+void wwv_find(int fdSer) {
     float new;
-    int find, meter[5], tx_mode;
+    int find, meter[6], tx_mode;
 
     rd_flags(fdSer);
     tx_mode = flag_data_return[3];
@@ -16,7 +14,7 @@ wwv_find(int fdSer) {
 
 
     freq_to_change_to = 2.5;
-    freq_out(fdSer, freq_to_change_to);
+    freq_out(fdSer);
     sleep(1);
     meter[1] = meter_rd(fdSer);
     find = meter[1];
