$NetBSD: patch-aux.c,v 1.1 2012/10/24 15:38:00 joerg Exp $

--- aux.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ aux.c
@@ -1,8 +1,6 @@
-extern main();
-extern freq_read();
-extern aux_comeback;
+#include "yaesu.h"
 
-aux(int fdSer) {
+void aux(int fdSer) {
    int selector;
    printf("\n1)  status_output    - Read frequency.\n");
    printf("2)  wwv_find         - Find strongest WWV station and set frequency.\n");
