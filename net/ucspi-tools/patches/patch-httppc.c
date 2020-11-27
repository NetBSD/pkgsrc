$NetBSD: patch-httppc.c,v 1.1 2020/11/27 11:34:17 schmonz Exp $

Use our dprintf() for portability.

--- httppc.c.orig	2016-09-21 22:05:29.000000000 +0000
+++ httppc.c
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <unistd.h>
 
+#include "fdprintf.h"
 #include "http_parser.h"
 
 #define READ_FD 6
