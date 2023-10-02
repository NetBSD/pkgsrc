$NetBSD: patch-Modules_socketmodule.c,v 1.1 2023/10/02 20:07:15 adam Exp $

--- Modules/socketmodule.c.orig	2022-01-13 18:52:14.000000000 +0000
+++ Modules/socketmodule.c
@@ -5440,7 +5440,7 @@ socket_sethostname(PyObject *self, PyObj
     Py_buffer buf;
     int res, flag = 0;
 
-#ifdef _AIX
+#if defined(_AIX) || (defined(__sun) && PKGSRC_OPSYS_VERSION < 051100)
 /* issue #18259, not declared in any useful header file */
 extern int sethostname(const char *, size_t);
 #endif
