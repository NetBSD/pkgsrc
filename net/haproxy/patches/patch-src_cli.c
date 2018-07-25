$NetBSD: patch-src_cli.c,v 1.2 2018/07/25 13:51:18 jperkin Exp $

Special handling for XPG4_2 on SunOS.

--- src/cli.c.orig	2018-06-27 14:27:32.000000000 +0000
+++ src/cli.c
@@ -11,6 +11,13 @@
  *
  */
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE 500
+#  else
+#define _XOPEN_SOURCE 600
+#  endif
+#endif
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
