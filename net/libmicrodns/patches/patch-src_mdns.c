$NetBSD: patch-src_mdns.c,v 1.1 2026/03/20 11:06:59 nia Exp $

Include <alloca.h> on platforms that require it.

--- src/mdns.c.orig	2026-03-20 10:15:11.833086734 +0000
+++ src/mdns.c
@@ -28,6 +28,9 @@
 # include "config.h"
 #endif
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
