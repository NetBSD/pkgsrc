$NetBSD: patch-libipv6calc_db_wrapper.c,v 1.1 2026/09/03 11:46:24 drixter Exp $

Fix build on SunOS

--- databases/lib/libipv6calc_db_wrapper.c.orig 2026-09-03 11:36:53.371346717 +0000
+++ databases/lib/libipv6calc_db_wrapper.c
@@ -38,6 +38,14 @@

 #include "libipv6calc.h"

+
+#ifdef __sun
+#define s6_addr8        _S6_un._S6_u8
+#define s6_addr16       _S6_un._S6_u16
+#define s6_addr32       _S6_un._S6_u32
+#endif
+
+
 #ifdef DOMAIN
 // fallback for IP2Location.h < 8.0.0 where "DOMAIN" is defined
 // code taken from https://stackoverflow.com/questions/994593/how-to-do-an-integer-log2-in-c

