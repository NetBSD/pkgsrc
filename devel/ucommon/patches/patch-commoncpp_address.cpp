$NetBSD: patch-commoncpp_address.cpp,v 1.1 2013/04/29 21:19:15 joerg Exp $

--- commoncpp/address.cpp.orig	2013-04-28 14:29:48.000000000 +0000
+++ commoncpp/address.cpp
@@ -1062,7 +1062,7 @@ void IPV4Cidr::set(const char *cp)
 #endif
 
     memset(&netmask, 0, sizeof(netmask));
-    bitset((bit_t *)&netmask, getMask(cp));
+    ::bitset((bit_t *)&netmask, getMask(cp));
     setString(cbuf, sizeof(cbuf), cp);
 
     ep = (char *)strchr(cp, '/');
@@ -1192,7 +1192,7 @@ void IPV6Cidr::set(const char *cp)
     char *ep;
 
     memset(&netmask, 0, sizeof(netmask));
-    bitset((bit_t *)&netmask, getMask(cp));
+    ::bitset((bit_t *)&netmask, getMask(cp));
     setString(cbuf, sizeof(cbuf), cp);
     ep = (char *)strchr(cp, '/');
     if(ep)
