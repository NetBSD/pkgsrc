$NetBSD: patch-session_session__test.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- session/session_test.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ session/session_test.cc
@@ -1974,11 +1974,11 @@ TEST_F(SessionTest, UpdatePreferences) {
   const size_t cascading_cand_size =
       command.output().candidates().candidate_size();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM
+#if defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM || defined(OS_NETBSD)
   EXPECT_EQ(no_cascading_cand_size, cascading_cand_size);
-#else   // defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM
+#else   // defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM || defined(OS_NETBSD)
   EXPECT_GT(no_cascading_cand_size, cascading_cand_size);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || OS_WASM || defined(OS_NETBSD)
 
   command.Clear();
   session->ConvertCancel(&command);
@@ -2149,7 +2149,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(0, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2159,13 +2159,13 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(9, output.all_candidate_words().candidates_size());
-#else   // OS_LINUX || OS_ANDROID || OS_WASM
+#else   // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
     // [ "あいうえお", "アイウエオ", "アイウエオ" (t13n), "あいうえお" (t13n),
     //   "aiueo" (t13n), "AIUEO" (t13n), "Aieuo" (t13n),
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX || OS_ANDROID || OS_WASM
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
   }
 
   command.Clear();
@@ -2177,7 +2177,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(1, output.all_candidate_words().focused_index());
     EXPECT_EQ(commands::CONVERSION, output.all_candidate_words().category());
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2187,13 +2187,13 @@ TEST_F(SessionTest, OutputAllCandidateWo
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(9, output.all_candidate_words().candidates_size());
-#else   // OS_LINUX || OS_ANDROID || OS_WASM
+#else   // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
     // [ "あいうえお", "アイウエオ",
     //   "aiueo" (t13n), "AIUEO" (t13n), "Aieuo" (t13n),
     //   "ａｉｕｅｏ"  (t13n), "ＡＩＵＥＯ" (t13n), "Ａｉｅｕｏ" (t13n),
     //   "ｱｲｳｴｵ" (t13n) ]
     EXPECT_EQ(11, output.all_candidate_words().candidates_size());
-#endif  // OS_LINUX || OS_ANDROID || OS_WASM
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
   }
 }
 
