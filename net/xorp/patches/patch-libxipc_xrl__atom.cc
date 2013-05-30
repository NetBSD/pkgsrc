$NetBSD: patch-libxipc_xrl__atom.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxipc/xrl_atom.cc.orig	2013-04-29 19:23:21.000000000 +0000
+++ libxipc/xrl_atom.cc
@@ -728,10 +728,10 @@ XrlAtom::packed_bytes() const
 	return bytes;
     }
 
-    static_assert(sizeof(IPv4) == 4);
-    static_assert(sizeof(IPv6) == 16);
-    static_assert(sizeof(IPv4Net) == sizeof(IPv4) + 4);
-    static_assert(sizeof(IPv6Net) == sizeof(IPv6) + 4);
+    my_static_assert(sizeof(IPv4) == 4);
+    my_static_assert(sizeof(IPv6) == 16);
+    my_static_assert(sizeof(IPv4Net) == sizeof(IPv4) + 4);
+    my_static_assert(sizeof(IPv6Net) == sizeof(IPv6) + 4);
 
     switch (_type) {
     case xrlatom_no_type:
@@ -1090,7 +1090,7 @@ XrlAtom::pack_list(uint8_t* buffer, size
     size_t done = 0;
 
     uint32_t nelem = htonl(_list->size());
-    static_assert(sizeof(nelem) == 4);
+    my_static_assert(sizeof(nelem) == 4);
 
     memcpy(buffer, &nelem, sizeof(nelem));
     done += sizeof(nelem);
