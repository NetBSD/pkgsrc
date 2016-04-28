$NetBSD: patch-src_samplerate_src__sinc.c,v 1.2 2016/04/28 19:23:21 adam Exp $

Needed for int32_t on SunOS

--- src/samplerate/src_sinc.c.orig	2013-08-19 23:51:25.000000000 +0000
+++ src/samplerate/src_sinc.c
@@ -26,6 +26,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__sun)
+#include <sys/types.h>
+#endif
 
 #include "float_cast.h"
 #include "common.h"
