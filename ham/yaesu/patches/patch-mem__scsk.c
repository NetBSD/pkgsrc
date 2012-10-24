$NetBSD: patch-mem__scsk.c,v 1.1 2012/10/24 15:38:02 joerg Exp $

--- mem_scsk.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ mem_scsk.c
@@ -1,6 +1,6 @@
-extern main();
+#include "yaesu.h"
 
-mem_scsk(int fdSer) {
+void mem_scsk(int fdSer) {
     int opcode, memory_channel, scanning_include;
  
     opcode = 0x8d;
