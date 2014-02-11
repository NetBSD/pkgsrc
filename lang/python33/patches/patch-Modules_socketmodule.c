$NetBSD: patch-Modules_socketmodule.c,v 1.1 2014/02/11 05:52:56 obache Exp $

* Fix vulnerability reported in SA56624, taken from upstream:
  http://hg.python.org/cpython/rev/7f176a45211f/

--- Modules/socketmodule.c.orig	2013-11-17 07:23:02.000000000 +0000
+++ Modules/socketmodule.c
@@ -2935,6 +2935,11 @@ sock_recvfrom_into(PySocketSockObject *s
     if (recvlen == 0) {
         /* If nbytes was not specified, use the buffer's length */
         recvlen = buflen;
+    } else if (recvlen > buflen) {
+        PyBuffer_Release(&pbuf);
+        PyErr_SetString(PyExc_ValueError,
+                        "nbytes is greater than the length of the buffer");
+        return NULL;
     }
 
     readlen = sock_recvfrom_guts(s, buf, recvlen, flags, &addr);
