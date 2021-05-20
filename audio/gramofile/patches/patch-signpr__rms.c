$NetBSD: patch-signpr__rms.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- signpr_rms.c.orig	2000-11-26 00:56:05.000000000 +0000
+++ signpr_rms.c
@@ -18,6 +18,7 @@
 #include "helpline.h"
 #endif
 #include <stdlib.h>
+#include <string.h>
 #include <stdio.h>
 #include <math.h>
 #ifndef SWIG
