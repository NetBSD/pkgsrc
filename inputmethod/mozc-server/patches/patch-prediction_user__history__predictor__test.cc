$NetBSD: patch-prediction_user__history__predictor__test.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- prediction/user_history_predictor_test.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ prediction/user_history_predictor_test.cc
@@ -2715,7 +2715,7 @@ TEST_F(UserHistoryPredictorTest, UserHis
 
   UserHistoryStorage storage1(filename);
 
-  UserHistoryPredictor::Entry *entry = storage1.add_entries();
+  UserHistoryPredictor::Entry *entry = storage1.user_history_base.add_entries();
   CHECK(entry);
   entry->set_key("key");
   entry->set_key("value");
@@ -2723,7 +2723,7 @@ TEST_F(UserHistoryPredictorTest, UserHis
   UserHistoryStorage storage2(filename);
   storage2.Load();
 
-  EXPECT_EQ(storage1.DebugString(), storage2.DebugString());
+  EXPECT_EQ(storage1.user_history_base.DebugString(), storage2.user_history_base.DebugString());
   FileUtil::Unlink(filename);
 }
 
