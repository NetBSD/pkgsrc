$NetBSD: patch-mode.c,v 1.1 2012/10/24 15:38:03 joerg Exp $

--- mode.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ mode.c
@@ -1,9 +1,8 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-mode (int fdSer) {
-   int opcode, mode, mode_num, tx_mode, bogus;
+void mode (int fdSer) {
+   int opcode, mode_num, tx_mode, bogus;
+   char mode;
    char cw_width, am_width;
 
     rd_flags(fdSer);
@@ -14,8 +13,8 @@ mode (int fdSer) {
        return;
     }
    printf("Input mode (single letter) -> ");
-   scanf(" %s", &mode);
-   mode = tolower(mode);
+   scanf(" %c", &mode);
+   mode = tolower((unsigned char)mode);
    switch(mode)
    {
    case 'l':
