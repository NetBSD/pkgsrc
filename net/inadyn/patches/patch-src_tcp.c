$NetBSD: patch-src_tcp.c,v 1.1 2015/04/04 07:59:34 snj Exp $

pull in time.h for struct timeval

--- src/tcp.c.orig	2015-04-03 21:27:23.000000000 -0700
+++ src/tcp.c	2015-04-03 21:30:17.000000000 -0700
@@ -23,6 +23,7 @@
 #include <poll.h>
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 
 #include "debug.h"
 #include "tcp.h"
