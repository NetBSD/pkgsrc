$NetBSD: patch-external-libfetch-http.c,v 1.1.1.1 2015/12/31 18:29:50 agc Exp $

make sure time.h is included first so we don't get linker warnings

--- external/libfetch/http.c	2015/12/29 00:34:33	1.1
+++ external/libfetch/http.c	2015/12/29 00:35:12
@@ -62,7 +62,6 @@
 #define _XOPEN_SOURCE
 #include <sys/param.h>
 #include <sys/socket.h>
-#include <sys/time.h>
 
 #include <ctype.h>
 #include <err.h>
