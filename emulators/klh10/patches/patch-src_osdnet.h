$NetBSD: patch-src_osdnet.h,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/osdnet.h.orig	2001-11-19 02:34:01.000000000 +0000
+++ src/osdnet.h
@@ -59,6 +59,9 @@
 #ifndef  KLH10_NET_DLPI	/* Solaris Data Link Provider Interface */
 # define KLH10_NET_DLPI 0
 #endif
+#ifndef  KLH10_NET_TAP_BRIDGE	/* BSD Ethernet Tunnel device + a bridge */
+# define KLH10_NET_TAP_BRIDGE 0
+#endif
 #ifndef  KLH10_NET_TUN	/* BSD IP Tunnel device */
 # define KLH10_NET_TUN 0
 #endif
@@ -67,14 +70,18 @@
 #endif
 
 #if !(KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_BPF || KLH10_NET_PFLT || \
-	KLH10_NET_TUN || KLH10_NET_LNX)
+	KLH10_NET_TUN || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE)
     /* None explicitly specified, pick a reasonable default */
-# if (CENV_SYS_FREEBSD && OSN_USE_IPONLY)
+# if ((CENV_SYS_NETBSD || CENV_SYS_FREEBSD) && OSN_USE_IPONLY)
 #  undef  KLH10_NET_TUN
 #  define KLH10_NET_TUN 1
 # elif (CENV_SYS_NETBSD || CENV_SYS_FREEBSD)
-#  undef  KLH10_NET_BPF
-#  define KLH10_NET_BPF 1
+/*
+ * #  undef  KLH10_NET_BPF
+ * #  define KLH10_NET_BPF 1
+ */
+#  undef  KLH10_NET_TAP_BRIDGE
+#  define KLH10_NET_TAP_BRIDGE 1
 # elif CENV_SYS_DECOSF
 #  undef  KLH10_NET_PFLT
 #  define KLH10_NET_PFLT 1
