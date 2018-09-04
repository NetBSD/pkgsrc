$NetBSD: patch-checkpeerlocal.c,v 1.1 2018/09/04 11:00:48 wiz Exp $

IPv6 guards added (build fails without IPv6 otherwise).

--- checkpeerlocal.c.orig	2018-08-24 15:30:42.000000000 +0000
+++ checkpeerlocal.c
@@ -208,6 +208,7 @@ int checkpeerlocal(int sock)
     }
 #endif
 
+#ifdef HAVE_IPV6
     if (IN6_IS_ADDR_V4MAPPED(&addr.sin6.sin6_addr)) {
 	    /* map to IPv4 */
 	    struct sockaddr_in si;
@@ -216,6 +217,7 @@ int checkpeerlocal(int sock)
 	    memcpy(&addr.sin, &si, sizeof(struct sockaddr_in));
 	    D(pat(&addr.sa));
     }
+#endif
 
     if (getifaddrs(&ifap) != 0) {
 	D(printf("getifaddrs failed: %s\n", strerror(errno)));
