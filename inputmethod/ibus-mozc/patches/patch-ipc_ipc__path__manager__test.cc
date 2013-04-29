$NetBSD: patch-ipc_ipc__path__manager__test.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- ipc/ipc_path_manager_test.cc.orig	2013-03-29 04:33:26.000000000 +0000
+++ ipc/ipc_path_manager_test.cc
@@ -103,7 +103,7 @@ TEST_F(IPCPathManagerTest, IPCPathManage
   EXPECT_FALSE(manager->GetServerProductVersion().empty());
   EXPECT_GT(manager->GetServerProcessId(), 0);
   EXPECT_EQ(t.path(), path);
-#ifdef OS_LINUX
+#if defned(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, |path| should be abstract (see man unix(7) for details.)
   ASSERT_FALSE(path.empty());
   EXPECT_EQ('\0', path[0]);
