$NetBSD: patch-modes.c,v 1.1 2021/12/30 00:43:35 nia Exp $

Need string.h for memcpy().

--- modes.c.orig	1998-05-24 02:23:12.000000000 +0000
+++ modes.c
@@ -11,6 +11,7 @@
 #include <X11/Xutil.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include "trippy.h"
 #include "lmath.h"
