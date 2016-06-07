$NetBSD: patch-src_libguac_socket-fd.c,v 1.1 2016/06/07 12:09:38 jperkin Exp $

Include string.h for memset().

--- src/libguac/socket-fd.c.orig	2016-01-07 20:07:47.000000000 +0000
+++ src/libguac/socket-fd.c
@@ -28,6 +28,7 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/time.h>
 #include <unistd.h>
 
