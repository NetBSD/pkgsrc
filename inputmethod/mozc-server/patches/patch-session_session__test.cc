$NetBSD: patch-session_session__test.cc,v 1.2 2016/05/16 11:51:49 ryoon Exp $

--- session/session_test.cc.orig	2016-05-15 08:11:12.000000000 +0000
+++ session/session_test.cc
@@ -2136,11 +2136,11 @@ TEST_F(SessionTest, UpdatePreferences) {
   const size_t cascading_cand_size =
       command.output().candidates().candidate_size();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL
+#if defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL || defined(OS_NETBSD)
   EXPECT_EQ(no_cascading_cand_size, cascading_cand_size);
-#else  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL
+#else  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL || defined(OS_NETBSD)
   EXPECT_GT(no_cascading_cand_size, cascading_cand_size);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_NACL || defined(OS_NETBSD)
 
   command.Clear();
   session->ConvertCancel(&command);
@@ -2330,7 +2330,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(0, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2340,13 +2340,13 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(9, output.all_candidate_words().candidates_size());
-#else  // OS_LINUX || OS_ANDROID || OS_NACL
+#else  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
     // [ "あいうえお", "アイウエオ", "アイウエオ" (t13n), "あいうえお" (t13n),
     //   "aiueo" (t13n), "AIUEO" (t13n), "Aieuo" (t13n),
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
   }
 
   command.Clear();
@@ -2358,7 +2358,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(1, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2368,13 +2368,13 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(9, output.all_candidate_words().candidates_size());
-#else  // OS_LINUX || OS_ANDROID || OS_NACL
+#else  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
     // [ "あいうえお", "アイウエオ",
     //   "aiueo" (t13n), "AIUEO" (t13n), "Aieuo" (t13n),
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
   }
 }
 
