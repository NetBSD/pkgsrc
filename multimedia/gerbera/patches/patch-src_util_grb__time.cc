$NetBSD: patch-src_util_grb__time.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/util/grb_time.cc.orig	2026-01-03 10:16:00.906382021 +0000
+++ src/util/grb_time.cc
@@ -173,3 +173,11 @@ bool parseTime(int& value, std::string& 
         timeValue = fmt::to_string(value);
     return !list.empty();
 }
+
+std::string grbLocaltime(const std::string& format, const std::chrono::seconds& t)
+{
+    std::time_t time = t.count();
+    std::tm tm;
+    localtime_r(&time, &tm);
+    return fmt::format(format, tm);
+}
