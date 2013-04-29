$NetBSD: patch-session_session__test.cc,v 1.1 2013/04/29 09:52:18 ryoon Exp $

--- session/session_test.cc.orig	2013-03-29 04:33:26.000000000 +0000
+++ session/session_test.cc
@@ -2361,7 +2361,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(0, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2377,7 +2377,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
   }
 
   command.Clear();
@@ -2389,7 +2389,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(1, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2405,7 +2405,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
   }
 }
 
