$NetBSD: patch-Socket6.xs,v 1.4 2018/11/18 22:45:17 sevan Exp $

Minix currently lacks IPsec support.

--- Socket6.xs.orig	2018-11-18 22:39:33.471180000 +0000
+++ Socket6.xs
@@ -65,7 +65,8 @@ const struct in6_addr in6addr_loopback =
 # if (defined(__FreeBSD__) && __FreeBSD_version >= 700048) || \
      (defined(__NetBSD__) && __NetBSD_Version__ >= 899002500)
 #  include <netipsec/ipsec.h>
-# elif !defined(__OpenBSD__) && !defined(__DragonFly__)
+# elif !defined(__OpenBSD__) && !defined(__DragonFly__) && \
+     !defined(__Minix__)
 #  include <netinet6/ipsec.h>
 # endif
 #endif
