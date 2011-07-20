$NetBSD: patch-src_getdata.c,v 1.1 2011/07/20 07:03:53 adam Exp $

Don't include features.h; move string.h to dhcpd-pools.h.

--- src/getdata.c.orig	2011-07-20 06:30:23.000000000 +0000
+++ src/getdata.c
@@ -43,19 +43,12 @@ extern char *malloc();
 #define EXIT_SUCCESS    0	/* Successful exit status.  */
 #endif				/* STDC_HEADERS */
 
-#ifdef  HAVE_STRING_H
-#include <string.h>
-#else
-#include <strings.h>
-#endif
-
 #include <arpa/inet.h>
 #include <assert.h>
 #include <ctype.h>
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <features.h>
 #include <netinet/in.h>
 #include <stddef.h>
 #include <stdint.h>
