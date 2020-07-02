$NetBSD: patch-pdns_iputils.hh,v 1.5 2020/07/02 13:01:38 otis Exp $

Rename some identifiers to non-clashing names.

Reference:
https://github.com/PowerDNS/pdns/issues/9279

--- pdns/iputils.hh.orig	2020-04-06 12:07:50.000000000 +0000
+++ pdns/iputils.hh
@@ -339,9 +339,9 @@ union ComboAddress {
         index = 32 + index;
       }
 
-      uint32_t s_addr = ntohl(sin4.sin_addr.s_addr);
+      uint32_t ls_addr = ntohl(sin4.sin_addr.s_addr);
 
-      return ((s_addr & (1<<index)) != 0x00000000);
+      return ((ls_addr & (1<<index)) != 0x00000000);
     }
     if(isIPv6()) {
       if (index >= 128)
@@ -352,11 +352,11 @@ union ComboAddress {
         index = 128 + index;
       }
 
-      uint8_t *s_addr = (uint8_t*)sin6.sin6_addr.s6_addr;
+      uint8_t *ls_addr = (uint8_t*)sin6.sin6_addr.s6_addr;
       uint8_t byte_idx = index / 8;
       uint8_t bit_idx = index % 8;
 
-      return ((s_addr[15-byte_idx] & (1 << bit_idx)) != 0x00);
+      return ((ls_addr[15-byte_idx] & (1 << bit_idx)) != 0x00);
     }
     return false;
   }
