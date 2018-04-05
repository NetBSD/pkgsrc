$NetBSD: patch-src_cli.c,v 1.1 2018/04/05 09:18:39 jperkin Exp $

Special handling for XPG4_2 on SunOS.

--- src/cli.c.orig	2018-02-08 13:05:15.000000000 +0000
+++ src/cli.c
@@ -11,6 +11,9 @@
  *
  */
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE
+#endif
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
