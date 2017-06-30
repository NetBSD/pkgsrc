$NetBSD: patch-resize.c,v 1.1 2017/06/30 11:07:26 jperkin Exp $

Handle include-what-you-use breakage.

--- resize.c.orig	2017-06-09 10:52:07.000000000 +0000
+++ resize.c
@@ -19,6 +19,7 @@
 #include <fcntl.h>
 #include <stdbool.h>
 #include <stdlib.h>
+#include <termios.h>
 #include <unistd.h>
 #include "lib.h"
 #include "mutt_curses.h"
