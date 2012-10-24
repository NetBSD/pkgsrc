$NetBSD: patch-lock.c,v 1.1 2012/10/24 15:38:01 joerg Exp $

--- lock.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ lock.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-lock(int fdSer) {
+void lock(int fdSer) {
     int opcode, lock_toggler;
     char locker;
     rd_flags(fdSer);
