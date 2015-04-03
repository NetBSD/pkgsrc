$NetBSD: patch-bin_exporter.c,v 1.1 2015/04/03 10:18:53 hiramatsu Exp $

add missing sys/time.h header

--- bin/exporter.c.orig        2014-02-16 12:59:29.000000000 +0000
+++ bin/exporter.c
@@ -36,6 +36,7 @@

 #include "config.h"

+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
