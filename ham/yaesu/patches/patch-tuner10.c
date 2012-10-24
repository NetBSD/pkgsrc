$NetBSD: patch-tuner10.c,v 1.1 2012/10/24 15:38:06 joerg Exp $

--- tuner10.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ tuner10.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-tuner10(int fdSer) {
+void tuner10(int fdSer) {
    /*
     *  I do not know if this function works, I do not have a 
     *  tuner to test it with.
