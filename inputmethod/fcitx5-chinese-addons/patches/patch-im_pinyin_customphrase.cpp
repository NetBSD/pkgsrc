$NetBSD: patch-im_pinyin_customphrase.cpp,v 1.1 2026/09/20 18:02:49 wiz Exp $

fmt::localtime was removed in fmt 1.12.

--- im/pinyin/customphrase.cpp.orig	2026-09-20 17:51:01.949877388 +0000
+++ im/pinyin/customphrase.cpp
@@ -114,7 +114,10 @@ inline std::tm currentTm() {
     std::chrono::system_clock::time_point now =
         std::chrono::system_clock::now();
     std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
-    return fmt::localtime(currentTime);
+
+    std::tm localtime{};
+    localtime_r(&currentTime, &localtime);
+    return localtime;
 #endif
 }
 
