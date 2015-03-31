$NetBSD: patch-examples_dvbinfo_udp.c,v 1.3 2015/03/31 15:52:51 joerg Exp $

Portability fix from upstream (Jean-Paul Saman <jpsaman@videolan.org>).
Don't cast alignments away.

--- examples/dvbinfo/udp.c.orig	2014-04-16 07:22:14.000000000 +0000
+++ examples/dvbinfo/udp.c
@@ -61,43 +61,53 @@
 #   include <fcntl.h>
 #endif
 
+#ifndef SOL_IP
+#   define SOL_IP IPPROTO_IP
+#endif
+#ifndef SOL_IPV6
+#   define SOL_IPV6 IPPROTO_IPV6
+#endif
+#ifndef IPPROTO_IPV6
+# define IPPROTO_IPV6 41 /* IANA */
+#endif
+
 #include <assert.h>
 
 #include "udp.h"
 
 #ifdef HAVE_SYS_SOCKET_H
-static bool is_multicast(const struct sockaddr_storage *saddr, socklen_t len)
+static bool is_multicast(const struct sockaddr *addr, socklen_t len)
 {
-    const struct sockaddr *addr = (const struct sockaddr *) saddr;
 
     switch(addr->sa_family)
     {
 #if defined(IN_MULTICAST)
         case AF_INET:
         {
-            const struct sockaddr_in *ip = (const struct sockaddr_in *)saddr;
-            if ((size_t)len < sizeof (*ip))
+            struct sockaddr_in ip;
+            if ((size_t)len < sizeof (ip))
                 return false;
-            return IN_MULTICAST(ntohl(ip->sin_addr.s_addr)) != 0;
+            memcpy(&ip, addr, sizeof(ip));
+            return IN_MULTICAST(ntohl(ip.sin_addr.s_addr)) != 0;
         }
 #endif
 #if defined(IN6_IS_ADDR_MULTICAST)
         case AF_INET6:
         {
-            const struct sockaddr_in6 *ip6 = (const struct sockaddr_in6 *)saddr;
-            if ((size_t)len < sizeof (*ip6))
+            struct sockaddr_in6 ip6;
+            if ((size_t)len < sizeof (ip6))
                 return false;
-            return IN6_IS_ADDR_MULTICAST(&ip6->sin6_addr) != 0;
+            memcpy(&ip6, addr, sizeof(ip6));
+            return IN6_IS_ADDR_MULTICAST(&ip6.sin6_addr) != 0;
         }
 #endif
     }
     return false;
 }
 
-static bool mcast_connect(int s, const char *interface, const struct sockaddr_storage *saddr, socklen_t len)
+static bool mcast_connect(int s, const char *interface, const struct sockaddr *addr, socklen_t len)
 {
     unsigned int ifindex = interface ? if_nametoindex(interface) : 0;
-    const struct sockaddr *addr = (const struct sockaddr *) saddr;
 
 #if defined(MCAST_JOIN_GROUP)
     /* Source Specific Multicast Join */
@@ -115,10 +125,13 @@ static bool mcast_connect(int s, const c
     {
         case AF_INET6:
         {
-            const struct sockaddr_in6 *sin6 = (const struct sockaddr_in6 *)saddr;
+            struct sockaddr_in6 sin6;
             assert(len >= sizeof (struct sockaddr_in6));
-            if (sin6->sin6_scope_id != 0)
-                greq.gr_interface = sin6->sin6_scope_id;
+            memcpy(&sin6, addr, sizeof(sin6));
+            if (sin6.sin6_scope_id != 0) {
+                greq.gr_interface = sin6.sin6_scope_id;
+                memcpy(&greq.gr_group, &sin6, sizeof(sin6));
+            }
             if (setsockopt(s, SOL_IPV6, MCAST_JOIN_GROUP, &greq, sizeof(greq)) == 0)
                 return true;
             break;
@@ -136,12 +149,14 @@ static bool mcast_connect(int s, const c
         case AF_INET6:
         {
             struct ipv6_mreq ipv6mr;
-            const struct sockaddr_in6 *ip6 = (const struct sockaddr_in6 *)saddr;
+            struct sockaddr_in6 ip6;
+            assert(len >= sizeof (struct sockaddr_in6));
+            memcpy(&ip6, addr, sizeof(ip6));
 
             memset(&ipv6mr, 0, sizeof (ipv6mr));
             assert(len >= sizeof (struct sockaddr_in6));
-            ipv6mr.ipv6mr_multiaddr = ip6->sin6_addr;
-            ipv6mr.ipv6mr_interface = (ifindex > 0) ? ifindex : ip6->sin6_scope_id;
+            ipv6mr.ipv6mr_multiaddr = ip6.sin6_addr;
+            ipv6mr.ipv6mr_interface = (ifindex > 0) ? ifindex : ip6.sin6_scope_id;
 # ifdef IPV6_JOIN_GROUP
             if (setsockopt(s, SOL_IPV6, IPV6_JOIN_GROUP, &ipv6mr, sizeof (ipv6mr)) == 0)
 # else
@@ -154,10 +169,12 @@ static bool mcast_connect(int s, const c
         case AF_INET:
         {
             struct ip_mreq imr;
+            struct sockaddr_in ip;
 
             memset(&imr, 0, sizeof (imr));
             assert(len >= sizeof (struct sockaddr_in));
-            imr.imr_multiaddr = ((const struct sockaddr_in *)saddr)->sin_addr;
+            memcpy(&ip, addr, sizeof(ip));
+            imr.imr_multiaddr = ip.sin_addr;
 #if 0       /* TODO: Source Specific Multicast Join */
             if (ifaddr) /* Linux specific interface bound multicast address */
                imr.imr_address.s_addr = if_addr;
@@ -284,9 +301,8 @@ int udp_open(const char *interface, cons
             continue;
         }
 
-        const struct sockaddr_storage *saddr = (const struct sockaddr_storage *)&ptr->ai_addr;
-        if (is_multicast(saddr, ptr->ai_addrlen) &&
-            mcast_connect(s_ctl, NULL, saddr, ptr->ai_addrlen))
+        if (is_multicast(ptr->ai_addr, ptr->ai_addrlen) &&
+            mcast_connect(s_ctl, NULL, ptr->ai_addr, ptr->ai_addrlen))
         {
             close(s_ctl);
             s_ctl = -1;
