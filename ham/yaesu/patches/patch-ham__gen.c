$NetBSD: patch-ham__gen.c,v 1.1 2012/10/24 15:38:01 joerg Exp $

--- ham_gen.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ ham_gen.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-ham_gen(int fdSer) {
+void ham_gen(int fdSer) {
    int opcode, ham_gen_byte;
 
    rd_flags(fdSer);
