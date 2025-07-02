$NetBSD: patch-util-src_pposix.c,v 1.2 2025/07/02 08:36:31 sborrill Exp $

Define _NETBSD_SOURCE for initgroups(), etc.

--- util-src/pposix.c.orig	2025-05-29 16:42:58.718566327 +0100
+++ util-src/pposix.c	2025-07-02 08:57:07.265785615 +0100
@@ -38,6 +38,12 @@
 #endif
 #endif
 
+#if defined(__NetBSD__)
+#ifndef _NETBSD_SOURCE
+#define _NETBSD_SOURCE
+#endif
+#endif
+
 #include <stdlib.h>
 #include <math.h>
 #include <unistd.h>
