$NetBSD: patch-src_cpython.h,v 1.1 2022/11/15 12:37:41 wiz Exp $

Fix build with python 3.11.
https://github.com/collectd/collectd/commit/623e95394e0e62e7f9ced2104b786d21e9c0bf53

--- src/cpython.h.orig	2020-07-20 09:50:14.293155228 +0000
+++ src/cpython.h
@@ -24,9 +24,16 @@
  *   Sven Trenkel <collectd at semidefinite.de>
  **/
 
+#include <Python.h>
 /* Some python versions don't include this by default. */
 
+#if PY_VERSION_HEX < 0x030B0000
+/*
+ * Python 3.11 move longintrepr.h to cpython/longintrepr.h
+ * And it's always included
+ */
 #include <longintrepr.h>
+#endif /* PY_VERSION_HEX < 0x030B0000 */
 
 /* These two macros are basically Py_BEGIN_ALLOW_THREADS and
  * Py_BEGIN_ALLOW_THREADS
