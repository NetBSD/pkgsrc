$NetBSD: patch-x11gfx.c,v 1.1 2013/03/25 01:59:03 dholland Exp $

--- x11gfx.c~	1994-04-15 21:19:58.000000000 +0000
+++ x11gfx.c
@@ -9,6 +9,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
