$NetBSD: patch-src_dhcpd-pools.h,v 1.1 2011/07/20 07:03:53 adam Exp $

Include <string.h> here.

--- src/dhcpd-pools.h.orig	2011-07-20 06:31:06.000000000 +0000
+++ src/dhcpd-pools.h
@@ -52,6 +52,12 @@ extern char *malloc();
 #define EXIT_SUCCESS	0
 #endif				/* STDC_HEADERS */
 
+#ifdef  HAVE_STRING_H
+#include <string.h>
+#else
+#include <strings.h>
+#endif
+
 #ifndef HAVE_PROGRAM_INVOCATION_SHORT_NAME
 #  ifdef HAVE___PROGNAME
 extern char *__progname;
