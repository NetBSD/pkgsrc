$NetBSD: patch-lib_isc_unix_net.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- lib/isc/unix/net.c.orig	2015-02-21 10:33:37.000000000 +0000
+++ lib/isc/unix/net.c
@@ -104,12 +104,12 @@ const struct in6_addr isc_net_in6addrloo
 
 # if defined(WANT_IPV6)
 static isc_once_t 	once_ipv6only = ISC_ONCE_INIT;
-# endif
 
 # if defined(ISC_PLATFORM_HAVEIPV6) && \
      defined(WANT_IPV6) && defined(ISC_PLATFORM_HAVEIN6PKTINFO)
 static isc_once_t 	once_ipv6pktinfo = ISC_ONCE_INIT;
 # endif
+# endif
 #endif /* ISC_PLATFORM_HAVEIPV6 */
 
 static isc_once_t 	once = ISC_ONCE_INIT;
