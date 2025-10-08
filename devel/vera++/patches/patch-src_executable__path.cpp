$NetBSD: patch-src_executable__path.cpp,v 1.1 2025/10/08 12:13:08 adam Exp $

Fix for deprecated boost::filesystem::path::normalize().

--- src/executable_path.cpp.orig	2025-10-08 11:29:16.461579509 +0000
+++ src/executable_path.cpp
@@ -42,7 +42,7 @@ std::string executable_path(const char *
     }
     boost::filesystem::path full_path(
         boost::filesystem::system_complete(
-            boost::filesystem::path(buf).normalize()));
+            boost::filesystem::path(buf).lexically_normal()));
     return full_path.string();
 }
 
