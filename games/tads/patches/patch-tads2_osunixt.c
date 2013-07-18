$NetBSD: patch-tads2_osunixt.c,v 1.1 2013/07/18 12:07:24 joerg Exp $

--- tads2/osunixt.c.orig	2013-07-17 14:34:13.000000000 +0000
+++ tads2/osunixt.c
@@ -32,6 +32,7 @@
 #include <stddef.h>
 #endif
 #include <stdlib.h>
+#include <termios.h>
 #include <ctype.h>
 #include <string.h>
 #include <sys/stat.h>
