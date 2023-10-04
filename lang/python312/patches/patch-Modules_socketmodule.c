$NetBSD: patch-Modules_socketmodule.c,v 1.2 2023/10/04 13:19:49 jperkin Exp $

SunOS needs _XOPEN_SOURCE for sendmsg bits that are now required.

--- Modules/socketmodule.c.orig	2023-10-02 11:48:14.000000000 +0000
+++ Modules/socketmodule.c
@@ -89,6 +89,9 @@ Local naming conventions:
 #  define Py_BUILD_CORE_MODULE 1
 #endif
 
+#ifdef __sun
+#define _XOPEN_SOURCE	600
+#endif
 #ifdef __APPLE__
 // Issue #35569: Expose RFC 3542 socket options.
 #define __APPLE_USE_RFC_3542 1
@@ -5655,7 +5658,7 @@ socket_sethostname(PyObject *self, PyObj
     Py_buffer buf;
     int res, flag = 0;
 
-#ifdef _AIX
+#if defined(_AIX) || (defined(__sun) && PKGSRC_OPSYS_VERSION < 051100)
 /* issue #18259, not declared in any useful header file */
 extern int sethostname(const char *, size_t);
 #endif
