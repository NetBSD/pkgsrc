$NetBSD: patch-splt__tog.c,v 1.1 2012/10/24 15:38:05 joerg Exp $

--- splt_tog.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ splt_tog.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-splt_tog(int fdSer) {
+void splt_tog(int fdSer) {
    int opcode, split_toggler, split_byte, tx_mode;
     rd_flags(fdSer);
     tx_mode = flag_data_return[3];
