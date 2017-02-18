$NetBSD: patch-amtterm.c,v 1.1 2017/02/18 13:58:33 joerg Exp $

--- amtterm.c.orig	2017-02-18 02:24:13.146730774 +0000
+++ amtterm.c
@@ -27,6 +27,7 @@
 #include <termios.h>
 #include <signal.h>
 #include <sys/ioctl.h>
+#include <sys/time.h>
 
 #include "redir.h"
 
