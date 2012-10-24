$NetBSD: patch-save__mem.c,v 1.1 2012/10/24 15:38:05 joerg Exp $

--- save_mem.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ save_mem.c
@@ -1,14 +1,9 @@
 #include <sys/file.h>
 #include <stdio.h>
-#include <config.h>
-extern main();
-extern stat_upd();
-extern rd_flags();
-extern int data_return_param;
-extern data_array[];
-extern outport();
+#include "config.h"
+#include "yaesu.h"
 
-mem_save(int fdSer) {
+void mem_save(int fdSer) {
     int opcode, n, freq;
     int memory_contents[650];
     FILE *mem_fd;
