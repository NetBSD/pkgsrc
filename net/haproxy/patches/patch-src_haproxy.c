$NetBSD: patch-src_haproxy.c,v 1.1 2018/04/05 09:18:39 jperkin Exp $

Special handling for XPG4_2 on SunOS.

--- src/haproxy.c.orig	2018-02-08 13:05:15.000000000 +0000
+++ src/haproxy.c
@@ -26,6 +26,9 @@
  */
 
 #define _GNU_SOURCE
+#if defined(__sun) && !defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
