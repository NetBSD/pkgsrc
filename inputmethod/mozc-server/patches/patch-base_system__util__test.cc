$NetBSD: patch-base_system__util__test.cc,v 1.1 2024/02/10 01:17:27 ryoon Exp $

--- base/system_util_test.cc.orig	2023-12-13 09:25:13.483600855 +0000
+++ base/system_util_test.cc
@@ -59,7 +59,7 @@ TEST_F(SystemUtilTest, GetUserProfileDir
 #elif defined(__APPLE__)
   // TODO(komatsu): write a test.
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
   EnvironMock environ_mock;
   FileUtilMock file_util_mock;
   SystemUtil::SetUserProfileDirectory("");
