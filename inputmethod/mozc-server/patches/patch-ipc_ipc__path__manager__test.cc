$NetBSD: patch-ipc_ipc__path__manager__test.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- ipc/ipc_path_manager_test.cc.orig	2013-07-17 02:37:50.000000000 +0000
+++ ipc/ipc_path_manager_test.cc
@@ -103,7 +103,7 @@ TEST_F(IPCPathManagerTest, IPCPathManage
   EXPECT_FALSE(manager->GetServerProductVersion().empty());
   EXPECT_GT(manager->GetServerProcessId(), 0);
   EXPECT_EQ(t.path(), path);
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, |path| should be abstract (see man unix(7) for details.)
   ASSERT_FALSE(path.empty());
   EXPECT_EQ('\0', path[0]);
