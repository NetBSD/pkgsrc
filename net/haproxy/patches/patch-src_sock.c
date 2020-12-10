$NetBSD: patch-src_sock.c,v 1.2 2020/12/10 09:34:21 jperkin Exp $

Special handling for XPG4_2 on SunOS.

--- src/sock.c.orig	2020-11-28 15:51:33.000000000 +0000
+++ src/sock.c
@@ -11,6 +11,13 @@
  */
 
 #define _GNU_SOURCE
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
