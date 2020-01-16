$NetBSD: patch-resize.c,v 1.3 2020/01/16 13:52:39 tm Exp $

Required to have the correct struct information for winsize.

--- resize.c.orig	2019-11-29 15:02:20.000000000 +0000
+++ resize.c
@@ -43,6 +43,7 @@
 #include <ioctl.h>
 #endif
 #endif
+#include <termios.h>
 
 /**
  * mutt_get_winsize - Use an ioctl to get the window size
