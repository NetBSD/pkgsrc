$NetBSD: patch-libxipc_xuid.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxipc/xuid.cc.orig	2013-04-29 19:23:19.000000000 +0000
+++ libxipc/xuid.cc
@@ -109,8 +109,8 @@ static const uint32_t XUID_CSTR_BYTES = 
 
 XUID::XUID(const string& s) throw (InvalidString)
 {
-    static_assert(sizeof(_data) == 16);
-    static_assert(sizeof(_data[0]) == 4);
+    my_static_assert(sizeof(_data) == 16);
+    my_static_assert(sizeof(_data[0]) == 4);
 
     if (s.size() < XUID_CSTR_BYTES)
 	throw InvalidString();
@@ -133,8 +133,8 @@ XUID::operator==(const XUID& x) const
 bool
 XUID::operator<(const XUID& x) const
 {
-    static_assert(sizeof(_data) == 16);
-    static_assert(sizeof(_data[0]) == 4);
+    my_static_assert(sizeof(_data) == 16);
+    my_static_assert(sizeof(_data[0]) == 4);
     int i;
 
     for (i = 0; i < 3; i++) {	// Loop ends intentionally at 3 not 4.
