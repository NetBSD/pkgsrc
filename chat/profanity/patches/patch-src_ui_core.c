$NetBSD: patch-src_ui_core.c,v 1.1 2023/11/08 16:37:46 nros Exp $

sys/termios.h is needed for TIOCGWINZ on Solaris/Illumos

--- src/ui/core.c.orig	2023-11-08 17:16:57.233823491 +0000
+++ src/ui/core.c
@@ -55,6 +55,10 @@
 #include <curses.h>
 #endif
 
+#ifdef HAVE_SYS_TERMIOS_H
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
