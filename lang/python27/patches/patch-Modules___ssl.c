$NetBSD: patch-Modules___ssl.c,v 1.3 2013/11/12 18:57:25 adam Exp $

Cygwin fix from cygport 2.6.2-ssl-threads.patch

--- Modules/_ssl.c.orig	2013-11-10 07:36:41.000000000 +0000
+++ Modules/_ssl.c
@@ -16,6 +16,10 @@
 
 #include "Python.h"
 
+#ifdef __CYGWIN__
+#undef WITH_THREAD
+#endif
+
 #ifdef WITH_THREAD
 #include "pythread.h"
 
