$NetBSD: patch-src_hitch.c,v 1.1 2016/05/25 20:15:35 fhajny Exp $

Need sys/filio on SunOS for FIONBIO.

--- src/hitch.c.orig	2016-01-26 14:58:56.000000000 +0000
+++ src/hitch.c
@@ -77,6 +77,10 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
+
 #include "uthash.h"
 #include "ringbuffer.h"
 #include "miniobj.h"
