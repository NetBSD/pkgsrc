$NetBSD: patch-ipc_ipc__path__manager__test.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- ipc/ipc_path_manager_test.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/ipc_path_manager_test.cc
@@ -102,7 +102,7 @@ TEST_F(IPCPathManagerTest, IPCPathManage
   EXPECT_FALSE(manager->GetServerProductVersion().empty());
   EXPECT_GT(manager->GetServerProcessId(), 0);
   EXPECT_EQ(t.path(), path);
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, |path| should be abstract (see man unix(7) for details.)
   ASSERT_FALSE(path.empty());
   EXPECT_EQ('\0', path[0]);
