$NetBSD: patch-libgnucash_engine_qoflog.cpp,v 1.2 2019/01/11 12:01:11 wiz Exp $

Fix error level type confusion.
https://bugs.gnucash.org/show_bug.cgi?id=797041

--- libgnucash/engine/qoflog.cpp.orig	2018-12-25 22:43:08.000000000 +0000
+++ libgnucash/engine/qoflog.cpp
@@ -429,22 +429,22 @@ qof_log_level_to_string(QofLogLevel log_
     const char *level_str;
     switch (log_level)
     {
-    case G_LOG_LEVEL_ERROR:
-        level_str = "ERROR";
+    case QOF_LOG_FATAL:
+        level_str = "FATAL";
         break;
-    case G_LOG_LEVEL_CRITICAL:
-        level_str = "CRIT";
+    case QOF_LOG_ERROR:
+        level_str = "ERROR";
         break;
-    case G_LOG_LEVEL_WARNING:
+    case QOF_LOG_WARNING:
         level_str = "WARN";
         break;
-    case G_LOG_LEVEL_MESSAGE:
+    case QOF_LOG_MESSAGE:
         level_str = "MESSG";
         break;
-    case G_LOG_LEVEL_INFO:
+    case QOF_LOG_INFO:
         level_str = "INFO";
         break;
-    case G_LOG_LEVEL_DEBUG:
+    case QOF_LOG_DEBUG:
         level_str = "DEBUG";
         break;
     default:
