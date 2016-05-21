$NetBSD: patch-plugins_sonypi_sonypi-plugin.c,v 1.1 2016/05/21 19:14:57 youri Exp $

SunOS needs sys/filio.h for _IOR()

--- plugins/sonypi/sonypi-plugin.c.orig	2015-10-06 16:57:49.000000000 +0000
+++ plugins/sonypi/sonypi-plugin.c
@@ -20,6 +20,10 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif /* HAVE_FCNTL_H */
