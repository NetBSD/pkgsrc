$NetBSD: patch-src_util_grb__time.h,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/util/grb_time.h.orig	2026-01-03 10:16:19.970930015 +0000
+++ src/util/grb_time.h
@@ -59,4 +59,7 @@ bool parseSimpleDate(const std::string& 
 bool parseTime(int& value, std::string& timeValue, GrbTimeType type = GrbTimeType::Seconds);
 std::string makeSimpleDate(std::string& s);
 
+/// @brief Converts seconds to localtime and prints a formatted string
+std::string grbLocaltime(const std::string& format, const std::chrono::seconds& t);
+
 #endif // __GRB_TIME_H__
