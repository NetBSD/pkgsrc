$NetBSD: patch-session_session__test.cc,v 1.5 2024/02/10 01:17:28 ryoon Exp $

--- session/session_test.cc.orig	2023-12-13 09:36:18.413874507 +0000
+++ session/session_test.cc
@@ -2011,7 +2011,7 @@ TEST_F(SessionTest, UpdatePreferences) {
   const size_t cascading_cand_size =
       command.output().candidates().candidate_size();
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
   EXPECT_EQ(cascading_cand_size, no_cascading_cand_size);
 #else   // __linux__ || __wasm__
   EXPECT_GT(no_cascading_cand_size, cascading_cand_size);
@@ -2200,7 +2200,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(output.all_candidate_words().focused_index(), 0);
     EXPECT_EQ(output.all_candidate_words().category(), commands::CONVERSION);
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
@@ -2228,7 +2228,7 @@ TEST_F(SessionTest, OutputAllCandidateWo
 
     EXPECT_EQ(output.all_candidate_words().focused_index(), 1);
     EXPECT_EQ(output.all_candidate_words().category(), commands::CONVERSION);
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
     // Cascading window is not supported on Linux, so the size of
     // candidate words is different from other platform.
     // TODO(komatsu): Modify the client for Linux to explicitly change
