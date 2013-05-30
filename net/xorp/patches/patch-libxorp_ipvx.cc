$NetBSD: patch-libxorp_ipvx.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/ipvx.cc.orig	2013-04-29 19:22:50.000000000 +0000
+++ libxorp/ipvx.cc
@@ -70,8 +70,8 @@ IPvX::IPvX(int family, const uint8_t *fr
 
 IPvX::IPvX(const IPv4& ipv4)
 {
-    static_assert(sizeof(_addr) >= sizeof(IPv4));
-    static_assert(sizeof(IPv4) == 4);
+    my_static_assert(sizeof(_addr) >= sizeof(IPv4));
+    my_static_assert(sizeof(IPv4) == 4);
 
     _af = AF_INET;
     memset(_addr, 0, sizeof(_addr));
@@ -80,8 +80,8 @@ IPvX::IPvX(const IPv4& ipv4)
 
 IPvX::IPvX(const IPv6& ipv6)
 {
-    static_assert(sizeof(_addr) >= sizeof(IPv6));
-    static_assert(sizeof(IPv6) == 16);
+    my_static_assert(sizeof(_addr) >= sizeof(IPv6));
+    my_static_assert(sizeof(IPv6) == 16);
 
     _af = AF_INET6;
     memcpy(_addr, &ipv6, 16);
@@ -197,7 +197,7 @@ IPvX::operator>>(uint32_t right_shift) c
 bool
 IPvX::operator<(const IPvX& other) const
 {
-    static_assert(sizeof(_addr) == 16);
+    my_static_assert(sizeof(_addr) == 16);
     int i;
 
     for (i = 0; i < 3; i++) {	// Loop ends intentionally at 3 not 4.
