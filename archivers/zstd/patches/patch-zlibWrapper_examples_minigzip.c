$NetBSD: patch-zlibWrapper_examples_minigzip.c,v 1.1 2018/10/17 08:59:16 jperkin Exp $

Set _POSIX_SOURCE correctly.

--- zlibWrapper/examples/minigzip.c.orig	2018-10-05 16:34:52.000000000 +0000
+++ zlibWrapper/examples/minigzip.c
@@ -20,3 +20,5 @@
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_SOURCE /* fileno */
+#endif
 
