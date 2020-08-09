$NetBSD: patch-lib_isc_unix_net.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Fix build on SmartOS. In this special case, _XOPEN_SOURCE has to be only
  defined on SmartOS.

--- lib/isc/unix/net.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/unix/net.c
@@ -9,6 +9,15 @@
  * information regarding copyright ownership.
  */
 
+/* needed for CMSG_DATA */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include <stdbool.h>
 #include <sys/types.h>
 
