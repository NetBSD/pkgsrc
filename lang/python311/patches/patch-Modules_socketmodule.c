$NetBSD: patch-Modules_socketmodule.c,v 1.2 2023/01/14 17:23:26 wiz Exp $

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
