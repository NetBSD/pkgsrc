$NetBSD: patch-session_session__handler__scenario__test.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- session/session_handler_scenario_test.cc.orig	2023-12-13 09:39:32.677437804 +0000
+++ session/session_handler_scenario_test.cc
@@ -172,7 +172,7 @@ const char *kUsageStatsScenarioFileList[
     DATA_DIR "select_minor_prediction.txt",
     DATA_DIR "select_prediction.txt",
     DATA_DIR "select_t13n_by_key.txt",
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
     // This test requires cascading window.
     // TODO(hsumita): Removes this ifndef block.
     DATA_DIR "select_t13n_on_cascading_window.txt",
