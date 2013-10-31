$NetBSD: patch-src_common_tcpdump.c,v 1.1 2013/10/31 02:25:17 minskim Exp $

--- src/common/tcpdump.c.orig	2010-04-05 00:58:01.000000000 +0000
+++ src/common/tcpdump.c
@@ -59,7 +59,9 @@
 #endif
 
 #include "tcpdump.h"
+#ifndef HAVE_STRLCPY
 #include "lib/strlcpy.h"
+#endif
 
 #ifdef DEBUG
 extern int debug;
