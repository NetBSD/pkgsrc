$NetBSD: patch-include_spdlog_details_os-inl.h,v 1.1 2026/04/12 20:28:26 tnn Exp $

SunOS does not have tm_gmtoff

--- include/spdlog/details/os-inl.h.orig	2026-04-12 20:26:15.597056433 +0000
+++ include/spdlog/details/os-inl.h
@@ -260,6 +260,15 @@ SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm
     auto offset_seconds = utc_time_t - local_time_t;
     return static_cast<int>(offset_seconds / 60);
 }
+#elif defined(__sun)
+SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm) {
+    tzset();
+    int offset = -static_cast<int>(timezone / 60);
+    if (tm.tm_isdst > 0) {
+        offset += 60;
+    }
+    return offset;
+}
 #else
 // On unix simply use tm_gmtoff
 SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm) {
