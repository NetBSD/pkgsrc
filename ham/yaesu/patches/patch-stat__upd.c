$NetBSD: patch-stat__upd.c,v 1.1 2012/10/24 15:38:06 joerg Exp $

--- stat_upd.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ stat_upd.c
@@ -1,10 +1,6 @@
-extern main();
-extern data_array[];
-extern data_return_param;
-extern memory_number;
-extern outport();
+#include "yaesu.h"
 
-stat_upd(int fdSer) {
+void stat_upd(int fdSer) {
   int opcode, data_return_size;
   int n;
 /*
