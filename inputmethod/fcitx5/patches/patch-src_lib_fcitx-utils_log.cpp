$NetBSD: patch-src_lib_fcitx-utils_log.cpp,v 1.1 2025/12/07 00:17:25 maya Exp $

Avoid optional hunk of code that uses fmt::localtime, which was removed
in fmtlib 12.0.0.

This removes timestamps from logs.

--- src/lib/fcitx-utils/log.cpp.orig	2025-12-07 00:04:14.180802233 +0000
+++ src/lib/fcitx-utils/log.cpp
@@ -207,7 +207,7 @@ LogMessageBuilder::LogMessageBuilder(std
         break;
     }
 
-#if FMT_VERSION >= 50300
+#if FMT_VERSION >= 50300 && FMT_VERSION < 120000
     if (globalLogConfig.showTimeDate) {
         auto now = std::chrono::system_clock::now();
         auto floor = std::chrono::floor<std::chrono::seconds>(now);
