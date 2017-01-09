$NetBSD: patch-src_hitch.c,v 1.2 2017/01/09 13:02:20 fhajny Exp $

Need sys/filio on SunOS for FIONBIO.

--- src/hitch.c.orig	2016-11-11 13:10:38.000000000 +0000
+++ src/hitch.c
@@ -62,6 +62,10 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
+
 #include "config.h"
 #include "configuration.h"
 #include "hitch.h"
