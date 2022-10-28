$NetBSD: patch-test_unit.c,v 1.1 2022/10/28 17:58:03 he Exp $

Adapt to 64-bit time_t on NetBSD.

--- test/unit.c.orig	2019-03-22 02:15:59.000000000 +0000
+++ test/unit.c
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <inttypes.h>
 
 #include "Config.h"
 #include "URL.h"
@@ -168,7 +169,11 @@ static void testTime() {
                 
         printf("=> Test1: now\n");
         {
+#ifdef __NetBSD__
+                printf("\tResult: %" PRIu64 "\n", Time_now());
+#else
                 printf("\tResult: %ld\n", Time_now());
+#endif
         }
         printf("=> Test1: OK\n\n");
 
