$NetBSD: patch-xbmc_utils_test_TestSystemInfo.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/utils/test/TestSystemInfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/test/TestSystemInfo.cpp
@@ -73,6 +73,9 @@ TEST_F(TestSystemInfo, GetKernelName)
 #elif defined(TARGET_FREEBSD)
   EXPECT_STREQ("FreeBSD", g_sysinfo.GetKernelName(true).c_str()) << "'GetKernelName(true)' must return 'FreeBSD'";
   EXPECT_STREQ("FreeBSD", g_sysinfo.GetKernelName(false).c_str()) << "'GetKernelName(false)' must return 'FreeBSD'";
+#elif defined(TARGET_NETBSD)
+  EXPECT_STREQ("NetBSD", g_sysinfo.GetKernelName(true).c_str()) << "'GetKernelName(true)' must return 'NetBSD'";
+  EXPECT_STREQ("NetBSD", g_sysinfo.GetKernelName(false).c_str()) << "'GetKernelName(false)' must return 'NetBSD'";
 #elif defined(TARGET_DARWIN)
   EXPECT_STREQ("Darwin", g_sysinfo.GetKernelName(true).c_str()) << "'GetKernelName(true)' must return 'Darwin'";
   EXPECT_STREQ("Darwin", g_sysinfo.GetKernelName(false).c_str()) << "'GetKernelName(false)' must return 'Darwin'";
@@ -111,6 +114,9 @@ TEST_F(TestSystemInfo, GetOsName)
 #elif defined(TARGET_FREEBSD)
   EXPECT_STREQ("FreeBSD", g_sysinfo.GetOsName(true).c_str()) << "'GetOsName(true)' must return 'FreeBSD'";
   EXPECT_STREQ("FreeBSD", g_sysinfo.GetOsName(false).c_str()) << "'GetOsName(false)' must return 'FreeBSD'";
+#elif defined(TARGET_NETBSD)
+  EXPECT_STREQ("NetBSD", g_sysinfo.GetOsName(true).c_str()) << "'GetOsName(true)' must return 'NetBSD'";
+  EXPECT_STREQ("NetBSD", g_sysinfo.GetOsName(false).c_str()) << "'GetOsName(false)' must return 'NetBSD'";
 #elif defined(TARGET_DARWIN_IOS)
   EXPECT_STREQ("iOS", g_sysinfo.GetOsName(true).c_str()) << "'GetOsName(true)' must return 'iOS'";
   EXPECT_STREQ("iOS", g_sysinfo.GetOsName(false).c_str()) << "'GetOsName(false)' must return 'iOS'";
@@ -241,6 +247,8 @@ TEST_F(TestSystemInfo, GetUserAgent)
   EXPECT_EQ(g_sysinfo.GetUserAgent().find('('), g_sysinfo.GetUserAgent().find("(X11; ")) << "Second parameter in 'GetUserAgent()' string must start from 'X11; '";
 #if defined(TARGET_FREEBSD)
   EXPECT_EQ(g_sysinfo.GetUserAgent().find('('), g_sysinfo.GetUserAgent().find("(X11; FreeBSD ")) << "Second parameter in 'GetUserAgent()' string must start from 'X11; FreeBSD '";
+#if defined(TARGET_NETBSD)
+  EXPECT_EQ(g_sysinfo.GetUserAgent().find('('), g_sysinfo.GetUserAgent().find("(X11; NetBSD ")) << "Second parameter in 'GetUserAgent()' string must start from 'X11; NetBSD '";
 #elif defined(TARGET_LINUX)
   EXPECT_EQ(g_sysinfo.GetUserAgent().find('('), g_sysinfo.GetUserAgent().find("(X11; Linux ")) << "Second parameter in 'GetUserAgent()' string must start from 'X11; Linux '";
 #endif // defined(TARGET_LINUX)
