$NetBSD: patch-bin_pitch_swipe_swipe.c,v 1.1 2014/02/22 14:19:36 wiedi Exp $

include values.h for M_PI on SunOS
--- bin/pitch/swipe/swipe.c.orig	2012-12-22 12:25:38.000000000 +0000
+++ bin/pitch/swipe/swipe.c
@@ -80,6 +80,9 @@
 #endif
 
 #include <math.h>
+#if defined(__sun)
+#include <values.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
