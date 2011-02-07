$NetBSD: patch-src_intf.c,v 1.1 2011/02/07 05:45:18 obache Exp $

* Add support for SIOCGIFCONF interface

--- src/intf.c.orig	2006-01-09 07:09:49.000000000 +0000
+++ src/intf.c
@@ -55,6 +55,9 @@
 # define ifr_mtu	ifr_metric
 #endif
 
+#ifdef HAVE_IFREQ_IFR_SPACE
+# define NEXTIFR(i)	(i + 1)
+#else
 #ifdef HAVE_SOCKADDR_SA_LEN
 # define NEXTIFR(i)	((struct ifreq *)((u_char *)&i->ifr_addr + \
 				(i->ifr_addr.sa_len ? i->ifr_addr.sa_len : \
@@ -62,6 +65,7 @@
 #else
 # define NEXTIFR(i)	(i + 1)
 #endif
+#endif
 
 /* XXX - superset of ifreq, for portable SIOC{A,D}IFADDR */
 struct dnet_ifaliasreq {
