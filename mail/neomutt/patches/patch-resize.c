$NetBSD: patch-resize.c,v 1.4 2021/09/30 09:34:01 wiz Exp $

Required to have the correct struct information for winsize.
https://github.com/neomutt/neomutt/pull/3048

--- resize.c.orig	2019-11-29 15:02:20.000000000 +0000
+++ resize.c
@@ -43,6 +43,7 @@
 #include <ioctl.h>
 #endif
 #endif
+#include <termios.h>
 
 /**
  * mutt_get_winsize - Use an ioctl to get the window size
