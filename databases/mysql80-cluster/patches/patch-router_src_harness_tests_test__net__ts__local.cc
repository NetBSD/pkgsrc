$NetBSD: patch-router_src_harness_tests_test__net__ts__local.cc,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- router/src/harness/tests/test_net_ts_local.cc.orig	2022-03-23 13:49:36.000000000 +0000
+++ router/src/harness/tests/test_net_ts_local.cc
@@ -442,9 +442,9 @@ TYPED_TEST(LocalTwoWayProtocolTest, twow
     // EXPECT_EQ(peer_creds.value().cr_pid, getpid());
   }
 #elif defined(__NetBSD__)
-  EXPECT_EQ(peer_creds.value().unp_euid, geteuid());
-  EXPECT_EQ(peer_creds.value().unp_egid, getegid());
-  EXPECT_EQ(peer_creds.value().unp_pid, getpid());
+  EXPECT_EQ(peer_creds.value().cr_uid, geteuid());
+  EXPECT_EQ(peer_creds.value().cr_gid, getegid());
+  // EXPECT_EQ(peer_creds.value().unp_pid, getpid());
 #endif
 }
 
