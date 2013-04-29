$NetBSD: patch-config_stats__config__util__test.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- config/stats_config_util_test.cc.orig	2012-08-31 05:36:42.000000000 +0000
+++ config/stats_config_util_test.cc
@@ -708,13 +708,13 @@ TEST(StatsConfigUtilTestAndroid, Default
 }
 #endif  // OS_ANDROID
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 #ifndef OS_ANDROID
 TEST(StatsConfigUtilTestLinux, DefaultValueTest) {
   EXPECT_FALSE(StatsConfigUtil::IsEnabled());
 }
 #endif  // OS_ANDROID
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #else  // !GOOGLE_JAPANESE_INPUT_BUILD
 TEST(StatsConfigUtilTestNonOfficialBuild, DefaultValueTest) {
