$NetBSD: patch-term.c,v 1.2 2014/09/23 22:24:38 jperkin Exp $

--- term.c.orig	1997-01-24 16:36:57.000000000 +0000
+++ term.c
@@ -9,6 +9,11 @@
 
 #include "bbs.h"
 #include <sys/ioctl.h>
+#include <stdlib.h>
+#ifndef __sun
+#include <termcap.h>
+#endif
+#include <termios.h>
 
 #ifdef HP_UX
 #define O_HUPCL 01
