$NetBSD: patch-session_session__test.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- session/session_test.cc.orig	2012-08-31 05:36:43.000000000 +0000
+++ session/session_test.cc
@@ -2417,7 +2417,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(0, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2433,7 +2433,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
   }
 
   command.Clear();
@@ -2445,7 +2445,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(1, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
