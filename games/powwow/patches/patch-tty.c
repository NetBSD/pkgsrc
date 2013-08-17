$NetBSD: patch-tty.c,v 1.1 2013/08/17 11:14:54 joerg Exp $

--- tty.c.orig	2013-08-15 18:18:45.000000000 +0000
+++ tty.c
@@ -12,6 +12,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <termios.h>
 #include <time.h>
 #include <sys/types.h>
 #include <unistd.h>
