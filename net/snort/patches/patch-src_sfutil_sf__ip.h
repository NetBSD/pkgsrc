$NetBSD: patch-src_sfutil_sf__ip.h,v 1.1 2024/05/10 19:49:13 jperkin Exp $

Support SunOS.

--- src/sfutil/sf_ip.h.orig	2020-07-10 11:28:24.000000000 +0000
+++ src/sfutil/sf_ip.h
@@ -72,6 +72,12 @@
 
 #endif
 
+#ifdef __sun
+#define s6_addr8        _S6_un._S6_u8
+#define s6_addr16       _S6_un._S6_u16
+#define s6_addr32       _S6_un._S6_u32
+#endif
+
 #ifndef WIN32
 #if !defined(s6_addr8)
 #define s6_addr8  __u6_addr.__u6_addr8
