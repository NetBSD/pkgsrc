$NetBSD: patch-src_mongo_shell_shell__utils__extended.cpp,v 1.2 2023/07/29 11:45:43 adam Exp $

boost::filesystem::ofstream is deprected, use std::ofstream instead.

--- src/mongo/shell/shell_utils_extended.cpp.orig	2021-06-30 17:39:08.000000000 +0000
+++ src/mongo/shell/shell_utils_extended.cpp
@@ -390,7 +390,7 @@ BSONObj writeFile(const BSONObj& args, v
             mode |= std::ios::binary;
     }
 
-    boost::filesystem::ofstream ofs{normalizedFilePath, mode};
+    std::ofstream ofs{normalizedFilePath.string(), mode};
     uassert(40346,
             str::stream() << "failed to open file " << normalizedFilePath.string()
                           << " for writing",
@@ -454,7 +454,7 @@ BSONObj readDumpFile(const BSONObj& a, v
 
     // Open the file for reading in binary mode.
     const auto pathStr = a.firstElement().String();
-    boost::filesystem::ifstream stream(pathStr, std::ios::in | std::ios::binary);
+    ifstream stream(pathStr, std::ios::in | std::ios::binary);
     uassert(31405,
             str::stream() << "readDumpFile(): Unable to open file \"" << pathStr
                           << "\" for reading",
