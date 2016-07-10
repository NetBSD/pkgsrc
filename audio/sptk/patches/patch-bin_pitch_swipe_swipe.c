$NetBSD: patch-bin_pitch_swipe_swipe.c,v 1.2 2016/07/10 12:06:21 mef Exp $

include values.h for M_PI on SunOS

--- bin/pitch/swipe/swipe.c.orig	2015-12-14 14:38:40.000000000 +0900
+++ bin/pitch/swipe/swipe.c	2016-07-10 20:52:54.000000000 +0900
@@ -70,6 +70,9 @@
 #define VNUM    1.5 // current version
 
 #include <math.h>
+#if defined(__sun)
+#include <values.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
