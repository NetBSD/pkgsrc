$NetBSD: patch-server_tests_test-stream.c,v 1.1 2021/01/05 15:14:39 jperkin Exp $

Fix build on SunOS.

--- server/tests/test-stream.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/tests/test-stream.c
@@ -17,6 +17,14 @@
 */
 #include <config.h>
 
+#if defined(__sun)
+#  if __STDC_VERSION__ - 0 < 199901L
+#define _XOPEN_SOURCE	500
+#  else
+#define _XOPEN_SOURCE	600
+#  endif
+#endif
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <errno.h>
