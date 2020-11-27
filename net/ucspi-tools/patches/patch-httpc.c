$NetBSD: patch-httpc.c,v 1.1 2020/11/27 11:34:17 schmonz Exp $

Use our dprintf() for portability.

--- httpc.c.orig	2016-09-21 22:05:29.000000000 +0000
+++ httpc.c
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <unistd.h>
 
+#include "fdprintf.h"
 #include "http_parser.h"
 
 #define READ_FD 6
