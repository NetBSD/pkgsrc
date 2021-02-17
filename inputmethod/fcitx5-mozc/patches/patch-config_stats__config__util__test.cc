$NetBSD: patch-config_stats__config__util__test.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- config/stats_config_util_test.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ config/stats_config_util_test.cc
@@ -685,11 +685,11 @@ TEST(StatsConfigUtilTestAndroid, Default
 }
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 TEST(StatsConfigUtilTestLinux, DefaultValueTest) {
   EXPECT_FALSE(StatsConfigUtil::IsEnabled());
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #else  // !GOOGLE_JAPANESE_INPUT_BUILD
 TEST(StatsConfigUtilTestNonOfficialBuild, DefaultValueTest) {
