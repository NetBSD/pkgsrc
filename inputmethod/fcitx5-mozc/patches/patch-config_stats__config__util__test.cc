$NetBSD: patch-config_stats__config__util__test.cc,v 1.2 2024/02/10 12:26:02 ryoon Exp $

--- config/stats_config_util_test.cc.orig	2023-12-13 09:31:24.408148702 +0000
+++ config/stats_config_util_test.cc
@@ -688,7 +688,7 @@ TEST(StatsConfigUtilTestAndroid, Default
   EXPECT_FALSE(StatsConfigUtil::IsEnabled());
 #endif  // CHANNEL_DEV
 }
-#elif defined(__linux__)  // __ANDROID__
+#elif defined(__linux__) || defined(__NetBSD__)  // __ANDROID__
 TEST(StatsConfigUtilTestLinux, DefaultValueTest) {
   EXPECT_FALSE(StatsConfigUtil::IsEnabled());
 }
