$NetBSD: patch-tads2_osunixt.c,v 1.2 2021/12/29 09:36:37 dholland Exp $

Use standard headers. Use standard interfaces.

--- tads2/osunixt.c.orig	2005-06-02 16:54:38.000000000 +0000
+++ tads2/osunixt.c
@@ -32,6 +32,7 @@
 #include <stddef.h>
 #endif
 #include <stdlib.h>
+#include <termios.h>
 #include <ctype.h>
 #include <string.h>
 #include <sys/stat.h>
@@ -993,6 +994,9 @@ t_tty(int action)
         t.c_lflag |= INLCR;
         t.c_cc[VMIN] = 1;
         t.c_cc[VTIME] = 0;
+#ifndef XTABS
+#define XTABS OXTABS
+#endif
 #if !defined(SGI_IRIX)
         t.c_oflag &= (~XTABS);
 #else
@@ -1018,7 +1022,8 @@ t_tty(int action)
 #ifdef  USE_SGTTY
     ospeed = t.sg_ospeed;
 #else   
-    ospeed = t.c_cflag & CBAUD;
+    /*ospeed = t.c_cflag & CBAUD;*/
+    ospeed = cfgetospeed(&t);
 #endif
     if (ospeed == 0)
         ospeed = 11;
