$NetBSD: patch-src_manager_fd__extract.c,v 1.1 2012/11/19 03:03:42 joerg Exp $

--- src/manager/fd_extract.c.orig	2012-11-18 23:38:16.000000000 +0000
+++ src/manager/fd_extract.c
@@ -68,6 +68,7 @@
 #include <ntm_conf.h>
 #endif
 
+#include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -164,7 +165,7 @@ struct col_info *scan_col(void)
       n = getnbr();
       }
    if (n == RF_STATS) {
-      if (!nexttoken()) return;
+      if (!nexttoken()) return NULL;
       for (a = 0; a != 3; ++a) {
          scbuf[a] = ic;  nextchar();
          }
