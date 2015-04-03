$NetBSD: patch-bin_netflow__v1.c,v 1.1 2015/04/03 10:18:53 hiramatsu Exp $

add missing sys/time.h header

--- bin/netflow_v1.c.orig      2014-02-16 12:59:29.000000000 +0000
+++ bin/netflow_v1.c
@@ -39,6 +39,7 @@
 #include "config.h"

 #include <stdio.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
