$NetBSD: patch-psutil___psutil__bsd.c,v 1.10 2019/06/11 22:55:04 leot Exp $

Define proc_cwd on NetBSD >= 8.99.42.

--- psutil/_psutil_bsd.c.orig	2019-04-11 21:10:12.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -919,6 +921,8 @@ PsutilMethods[] = {
 #if defined(PSUTIL_FREEBSD) || defined(PSUTIL_OPENBSD)
     {"proc_connections", psutil_proc_connections, METH_VARARGS,
      "Return connections opened by process"},
+#endif
+#if defined(PSUTIL_FREEBSD) || defined(PSUTIL_OPENBSD) || (defined(PSUTIL_NETBSD) && __NetBSD_Version__ >= 899004200)
     {"proc_cwd", psutil_proc_cwd, METH_VARARGS,
      "Return process current working directory."},
 #endif
