$NetBSD: patch-strt__tun.c,v 1.1 2012/10/24 15:38:06 joerg Exp $

--- strt_tun.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ strt_tun.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-strt_tun(int fdSer) {
+void strt_tun(int fdSer) {
 
   /* 
    * I do not know if this function works, I do not have
