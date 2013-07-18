$NetBSD: patch-term.c,v 1.1 2013/07/18 12:07:24 joerg Exp $

--- term.c.orig	2013-07-18 10:12:24.000000000 +0000
+++ term.c
@@ -9,6 +9,9 @@
 
 #include "bbs.h"
 #include <sys/ioctl.h>
+#include <stdlib.h>
+#include <termcap.h>
+#include <termios.h>
 
 #ifdef HP_UX
 #define O_HUPCL 01
