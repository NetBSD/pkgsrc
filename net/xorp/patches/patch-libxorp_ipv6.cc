$NetBSD: patch-libxorp_ipv6.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/ipv6.cc.orig	2013-04-29 19:22:46.000000000 +0000
+++ libxorp/ipv6.cc
@@ -223,7 +223,7 @@ IPv6
 IPv6::operator<<(uint32_t ls) const
 {
     uint32_t tmp_addr[4];
-    static_assert(sizeof(_addr) == sizeof(tmp_addr));
+    my_static_assert(sizeof(_addr) == sizeof(tmp_addr));
 
     // Shift the words, and at the same time convert them into host-order
     switch (ls / 32) {
@@ -278,7 +278,7 @@ IPv6
 IPv6::operator>>(uint32_t rs) const
 {
     uint32_t tmp_addr[4];
-    static_assert(sizeof(_addr) == sizeof(tmp_addr));
+    my_static_assert(sizeof(_addr) == sizeof(tmp_addr));
 
     // Shift the words, and at the same time convert them into host-order
     switch (rs / 32) {
@@ -333,7 +333,7 @@ bool
 IPv6::operator<(const IPv6& other) const
 {
     int i;
-    static_assert(sizeof(_addr) == 16);
+    my_static_assert(sizeof(_addr) == 16);
 
     for (i = 0; i < 3; i++) {	// XXX: Loop ends intentionally at 3 not 4
 	if (_addr[i] != other._addr[i])
