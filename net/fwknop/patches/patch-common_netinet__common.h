$NetBSD: patch-common_netinet__common.h,v 1.1 2018/05/01 21:10:42 khorben Exp $

Add support for NetBSD.

--- common/netinet_common.h.orig	2016-06-09 01:01:53.000000000 +0000
+++ common/netinet_common.h
@@ -45,7 +45,7 @@
   #if HAVE_NETINET_IN_H
     #include <netinet/in.h>
   #endif
-  #if PLATFORM_OPENBSD  /* OpenBSD hack due to autoconf net/if.h difficulties */
+  #if PLATFORM_NETBSD || PLATFORM_OPENBSD  /* for autoconf net/if.h difficulties */
     #include <net/if.h>
     #include <net/ethertypes.h>
     #include <netinet/if_ether.h>
