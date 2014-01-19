$NetBSD: patch-commoncpp_address.cpp,v 1.3 2014/01/19 00:49:06 rodent Exp $

Be explicit that the local version of bitset is wanted, not the STL
version in std for C++11 libraries.

--- commoncpp/address.cpp.orig	2014-01-04 17:32:41.000000000 +0000
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
