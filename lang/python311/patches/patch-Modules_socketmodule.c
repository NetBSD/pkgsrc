$NetBSD: patch-Modules_socketmodule.c,v 1.1 2022/10/31 09:50:40 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2022-01-13 18:52:14.000000000 +0000
+++ Modules/socketmodule.c
@@ -2112,7 +2112,7 @@ getsockaddrarg(PySocketSockObject *s, Py
             PyObject *interfaceName;
             struct ifreq ifr;
             Py_ssize_t len;
-            struct sockaddr_can *addr = &addrbuf->can;
+            struct sockaddr_can *addr = (struct sockaddr_can *)addrbuf;
 
             if (!PyTuple_Check(args)) {
                 PyErr_Format(PyExc_TypeError,
@@ -5440,7 +5440,7 @@ socket_sethostname(PyObject *self, PyObj
     Py_buffer buf;
     int res, flag = 0;
 
-#ifdef _AIX
+#if defined(_AIX) || (defined(__sun) && PKGSRC_OPSYS_VERSION < 051100)
 /* issue #18259, not declared in any useful header file */
 extern int sethostname(const char *, size_t);
 #endif
