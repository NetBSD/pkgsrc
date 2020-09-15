$NetBSD: patch-include_HsNet.h,v 1.1 2020/09/15 15:34:05 jperkin Exp $

Spell uint32_t correctly.

--- include/HsNet.h.orig	2001-09-09 01:46:40.000000000 +0000
+++ include/HsNet.h
@@ -93,7 +93,7 @@ hsnet_inet_ntoa(
 #elif defined(HAVE_IN_ADDR_T)
              in_addr_t addr
 #elif defined(HAVE_INTTYPES_H)
-             u_int32_t addr
+             uint32_t addr
 #else
              unsigned long addr
 #endif
