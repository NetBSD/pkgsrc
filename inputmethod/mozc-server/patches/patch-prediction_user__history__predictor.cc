$NetBSD: patch-prediction_user__history__predictor.cc,v 1.1.2.2 2018/01/01 18:18:01 spz Exp $

- Apply a patch from the upstream pull request #424:
  https://github.com/google/mozc/pull/424/files

--- prediction/user_history_predictor.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ prediction/user_history_predictor.cc
@@ -841,7 +841,7 @@ bool UserHistoryPredictor::RomanFuzzyPre
       // swap.
       if (i + 1 < prefix.size()) {
         string swapped_prefix = prefix;
-        swap(swapped_prefix[i], swapped_prefix[i + 1]);
+        std::swap(swapped_prefix[i], swapped_prefix[i + 1]);
         if (Util::StartsWith(str, swapped_prefix)) {
           return true;
         }
