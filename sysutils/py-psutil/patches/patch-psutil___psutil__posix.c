$NetBSD: patch-psutil___psutil__posix.c,v 1.1 2015/12/01 14:07:36 ryoon Exp $

--- psutil/_psutil_posix.c.orig	2015-11-25 01:20:34.000000000 +0000
+++ psutil/_psutil_posix.c
@@ -26,7 +26,7 @@
 #include <linux/if_packet.h>
 #endif  // end linux
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <netdb.h>
 #include <netinet/in.h>
 #include <net/if_dl.h>
@@ -120,7 +120,7 @@ psutil_convert_ipaddr(struct sockaddr *a
         data = (const char *)lladdr->sll_addr;
     }
 #endif
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
     else if (addr->sa_family == AF_LINK) {
         // Note: prior to Python 3.4 socket module does not expose
         // AF_LINK so we'll do.
@@ -250,7 +250,7 @@ error:
  * net_if_stats() implementation. This is here because it is common
  * to both OSX and FreeBSD and I didn't know where else to put it.
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 
 #include <sys/sockio.h>
 #include <net/if_media.h>
@@ -478,7 +478,7 @@ PsutilMethods[] = {
      "Set process priority"},
     {"net_if_addrs", psutil_net_if_addrs, METH_VARARGS,
      "Retrieve NICs information"},
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
     {"net_if_stats", psutil_net_if_stats, METH_VARARGS,
      "Return NIC stats."},
 #endif
@@ -537,7 +537,7 @@ void init_psutil_posix(void)
     PyObject *module = Py_InitModule("_psutil_posix", PsutilMethods);
 #endif
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__sun) || defined(__NetBSD__)
     PyModule_AddIntConstant(module, "AF_LINK", AF_LINK);
 #endif
 
