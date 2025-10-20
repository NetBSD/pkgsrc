$NetBSD: patch-src_lib_base_Log.cpp,v 1.1 2025/10/20 19:49:12 tnn Exp $

Avoid requirement on newer compiler for now.
GCC 12 claims C++20 but has incomplete <format> support.
Reverts: https://github.com/deskflow/deskflow/commit/a6068ad6f64eee474d0cc5343db765dba0269034

--- src/lib/base/Log.cpp.orig	2025-10-20 18:41:42.807882627 +0000
+++ src/lib/base/Log.cpp
@@ -18,7 +18,7 @@
 #include <cstring>
 #include <ctime>
 
-#ifndef __APPLE__
+#if 0
 #include <format>
 #endif
 
@@ -73,7 +73,7 @@ void makeTimeString(std::vector<char> &b
   localtime_r(&t, &tm);
 #endif
 
-#ifndef __APPLE__
+#if 0
   std::format_to_n(
       buffer.data(), buffer.size(), "{:04}-{:02}-{:02}T{:02}:{:02}:{:02}", tm.tm_year + yearOffset,
       tm.tm_mon + monthOffset, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec
@@ -117,7 +117,7 @@ std::vector<char> makeMessage(const char
     bufferSize += filenameLength + lineNumberLength;
 
     std::vector<char> buffer(bufferSize);
-#ifndef __APPLE__
+#if 0
     std::format_to_n(
         buffer.data(), bufferSize, "[{}] {}: {}\n\t{}:{}", timeBuffer.data(), sectionName, message, filename, lineNumber
     );
@@ -129,7 +129,7 @@ std::vector<char> makeMessage(const char
     return buffer;
   } else {
     std::vector<char> buffer(bufferSize);
-#ifndef __APPLE__
+#if 0
     std::format_to_n(buffer.data(), bufferSize, "[{}] {}: {}", timeBuffer.data(), sectionName, message);
 #else
     snprintf(buffer.data(), bufferSize, "[%s] %s: %s", timeBuffer.data(), sectionName, message);
