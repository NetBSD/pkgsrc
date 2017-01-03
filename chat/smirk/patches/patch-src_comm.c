$NetBSD: patch-src_comm.c,v 1.1 2017/01/03 21:27:33 roy Exp $

--- src/comm.c.orig	2017-01-03 21:20:08.889101017 +0000
+++ src/comm.c
@@ -34,7 +34,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-
+#include <stdarg.h>
 
 #include "config.h"
 
