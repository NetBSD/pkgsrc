$NetBSD: patch-prediction_user__history__predictor.cc,v 1.2 2020/06/19 05:45:30 taca Exp $

- Apply a patch from the upstream pull request #424:
  https://github.com/google/mozc/pull/424/files
- Fix from https://github.com/google/mozc/issues/460

--- prediction/user_history_predictor.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ prediction/user_history_predictor.cc
@@ -298,23 +298,23 @@ bool UserHistoryStorage::Load() {
     return false;
   }
 
-  if (!ParseFromString(input)) {
+  if (!user_history_base.ParseFromString(input)) {
     LOG(ERROR) << "ParseFromString failed. message looks broken";
     return false;
   }
 
-  VLOG(1) << "Loaded user histroy, size=" << entries_size();
+  VLOG(1) << "Loaded user histroy, size=" << user_history_base.entries_size();
   return true;
 }
 
 bool UserHistoryStorage::Save() const {
-  if (entries_size() == 0) {
+  if (user_history_base.entries_size() == 0) {
     LOG(WARNING) << "etries size is 0. Not saved";
     return false;
   }
 
   string output;
-  if (!AppendToString(&output)) {
+  if (!user_history_base.AppendToString(&output)) {
     LOG(ERROR) << "AppendToString failed";
     return false;
   }
@@ -501,12 +501,12 @@ bool UserHistoryPredictor::Load() {
     return false;
   }
 
-  for (size_t i = 0; i < history.entries_size(); ++i) {
-    dic_->Insert(EntryFingerprint(history.entries(i)),
-                 history.entries(i));
+  for (size_t i = 0; i < history.user_history_base.entries_size(); ++i) {
+    dic_->Insert(EntryFingerprint(history.user_history_base.entries(i)),
+                 history.user_history_base.entries(i));
   }
 
-  VLOG(1) << "Loaded user histroy, size=" << history.entries_size();
+  VLOG(1) << "Loaded user histroy, size=" << history.user_history_base.entries_size();
 
   return true;
 }
@@ -528,13 +528,13 @@ bool UserHistoryPredictor::Save() {
 
   UserHistoryStorage history(filename);
   for (const DicElement *elm = tail; elm != nullptr; elm = elm->prev) {
-    history.add_entries()->CopyFrom(elm->value);
+    history.user_history_base.add_entries()->CopyFrom(elm->value);
   }
 
   // Updates usage stats here.
   UsageStats::SetInteger(
       "UserHistoryPredictorEntrySize",
-      static_cast<int>(history.entries_size()));
+      static_cast<int>(history.user_history_base.entries_size()));
 
   if (!history.Save()) {
     LOG(ERROR) << "UserHistoryStorage::Save() failed";
@@ -841,7 +841,7 @@ bool UserHistoryPredictor::RomanFuzzyPre
       // swap.
       if (i + 1 < prefix.size()) {
         string swapped_prefix = prefix;
-        swap(swapped_prefix[i], swapped_prefix[i + 1]);
+        std::swap(swapped_prefix[i], swapped_prefix[i + 1]);
         if (Util::StartsWith(str, swapped_prefix)) {
           return true;
         }
