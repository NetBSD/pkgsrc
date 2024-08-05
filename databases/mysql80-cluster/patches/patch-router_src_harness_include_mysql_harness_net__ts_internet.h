$NetBSD: patch-router_src_harness_include_mysql_harness_net__ts_internet.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- router/src/harness/include/mysql/harness/net_ts/internet.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ router/src/harness/include/mysql/harness/net_ts/internet.h
@@ -598,8 +598,12 @@ class resolver_base {
   static constexpr flags canonical_name = AI_CANONNAME;
   static constexpr flags numeric_host = AI_NUMERICHOST;
   static constexpr flags numeric_service = AI_NUMERICSERV;
+#ifdef AI_V4MAPPED
   static constexpr flags v4_mapped = AI_V4MAPPED;
+#endif
+#ifdef AI_ALL
   static constexpr flags all_matching = AI_ALL;
+#endif
   static constexpr flags address_configured = AI_ADDRCONFIG;
 };
 
