$NetBSD: patch-signpr__median.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- signpr_median.c.orig	2000-11-26 00:56:05.000000000 +0000
+++ signpr_median.c
@@ -18,6 +18,7 @@
 #include "helpline.h"
 #endif
 #include <stdlib.h>
+#include <string.h>
 #include <stdio.h>
 #ifndef SWIG
 #ifndef OLD_CURSES
