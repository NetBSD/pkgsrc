$NetBSD: patch-mem__hide.c,v 1.1 2012/10/24 15:38:02 joerg Exp $

--- mem_hide.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ mem_hide.c
@@ -1,7 +1,6 @@
-extern main();
-extern outport();
+#include "yaesu.h"
 
-mem_hide(int fdSer) {
+void mem_hide(int fdSer) {
     int opcode, memory_number, hide_byte;
     char hide_char;
     
