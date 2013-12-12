$NetBSD: patch-src_plugins_xfer_xfer-dcc.c,v 1.1 2013/12/12 20:17:56 jperkin Exp $

Need string.h

--- src/plugins/xfer/xfer-dcc.c.orig	2013-05-20 08:06:14.000000000 +0000
+++ src/plugins/xfer/xfer-dcc.c
@@ -20,6 +20,7 @@
  */
 
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
