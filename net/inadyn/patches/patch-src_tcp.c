$NetBSD: patch-src_tcp.c,v 1.2 2016/05/29 22:32:12 abs Exp $

pull in time.h for struct timeval

--- src/tcp.c.orig	2015-09-09 19:27:51.000000000 +0000
+++ src/tcp.c
@@ -23,6 +23,7 @@
 #include <poll.h>
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 
 #include "debug.h"
 #include "tcp.h"
