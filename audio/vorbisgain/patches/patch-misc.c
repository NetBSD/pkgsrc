$NetBSD: patch-misc.c,v 1.1 2026/03/16 12:17:18 nia Exp $

Fix implicit function declarations.

--- misc.c.orig	2026-03-16 12:02:57.932421804 +0000
+++ misc.c
@@ -10,10 +10,12 @@
 #include "config.h"
 #endif
 
+#include <sys/ioctl.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <vorbis/codec.h>
 #include "i18n.h"
 #include "misc.h"
@@ -30,10 +32,6 @@
 #include <termios.h>
 #endif
 
-#if GWINSZ_IN_SYS_IOCTL
-#include <sys/ioctl.h>
-#endif
-
 #endif /* DISABLE_WINSIZE */
 #endif /* WIN32 */
 
