$NetBSD: patch-mem__rec.c,v 1.1 2012/10/24 15:38:02 joerg Exp $

--- mem_rec.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ mem_rec.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-mem_rec(int fdSer) {
+void mem_rec(int fdSer) {
    int opcode;
    int memory_number, tx_mode;
 
