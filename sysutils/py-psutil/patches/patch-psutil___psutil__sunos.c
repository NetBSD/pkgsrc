$NetBSD: patch-psutil___psutil__sunos.c,v 1.1 2013/12/07 21:25:24 richard Exp $

--- psutil/_psutil_sunos.c.orig	2013-11-20 19:29:05.000000000 +0000
+++ psutil/_psutil_sunos.c
@@ -772,8 +772,9 @@ error:
     return NULL;
 }
 
-
+#ifndef EXPER_IP_AND_ALL_IRES
 #define EXPER_IP_AND_ALL_IRES   (1024+4)
+#endif
 
 // a signaler for connections without an actual status
 static int PSUTIL_CONN_NONE = 128;
@@ -790,7 +791,7 @@ static PyObject*
 get_process_connections(PyObject* self, PyObject* args)
 {
     long pid;
-    int sd = NULL;
+    int sd = 0;
     mib2_tcpConnEntry_t *tp = NULL;
     mib2_udpEntry_t     *ude;
 #if defined(AF_INET6)
@@ -1059,7 +1060,7 @@ error:
     Py_XDECREF(py_raddr);
     Py_DECREF(py_retlist);
     // TODO : free databuf
-    if (sd != NULL)
+    if (sd > 0)
         close(sd);
     return NULL;
 }
