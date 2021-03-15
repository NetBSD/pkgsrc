$NetBSD: patch-src_Listener.cpp,v 1.2 2021/03/15 17:00:06 gdt Exp $

Fix bug where the standards-specificed IPV6_JOIN_GROUP is not used.
See https://tools.ietf.org/html/rfc3493 on page 20.
See https://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_10_16

https://sourceforge.net/p/iperf2/tickets/103/

Fix bug where setsockopt was used with int when it is defined to use
unsigned char.  This should avoid bugs on BE machines.

https://sourceforge.net/p/iperf2/tickets/104/

--- src/Listener.cpp.orig	2019-01-22 20:31:17.000000000 +0000
+++ src/Listener.cpp
@@ -462,6 +462,9 @@ void Listener::McastJoin( ) {
 
 	} else {
 #ifdef HAVE_IPV6_MULTICAST
+#if !defined(IPV6_ADD_MEMBERSHIP) && defined(IPV6_JOIN_GROUP)
+#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
+#endif
 	    struct ipv6_mreq mreq;
 
 	    memcpy( &mreq.ipv6mr_multiaddr, SockAddr_get_in6_addr( &mSettings->local ),
@@ -759,8 +762,9 @@ int Listener::L2_setup (void) {
 void Listener::McastSetTTL( int val ) {
 #ifdef HAVE_MULTICAST
     if ( !SockAddr_isIPv6( &mSettings->local ) ) {
+        u_char uval = val;
         int rc = setsockopt( mSettings->mSock, IPPROTO_IP, IP_MULTICAST_TTL,
-                             (char*) &val, sizeof(val));
+                             (char*) &uval, sizeof(uval));
         WARN_errno( rc == SOCKET_ERROR, "multicast ttl" );
     }
 #ifdef HAVE_IPV6_MULTICAST
