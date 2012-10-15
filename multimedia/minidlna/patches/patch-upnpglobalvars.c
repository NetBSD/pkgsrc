$NetBSD: patch-upnpglobalvars.c,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- upnpglobalvars.c.orig	2012-10-15 19:22:17.000000000 +0000
+++ upnpglobalvars.c
@@ -48,7 +48,7 @@
  */
 #include <sys/types.h>
 #include <netinet/in.h>
-#include <linux/limits.h>
+#include <limits.h>
 
 #include "config.h"
 #include "upnpglobalvars.h"
