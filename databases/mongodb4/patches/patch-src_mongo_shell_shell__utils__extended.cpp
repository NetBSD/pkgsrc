$NetBSD: patch-src_mongo_shell_shell__utils__extended.cpp,v 1.1 2023/07/29 11:51:15 adam Exp $

boost::filesystem::ofstream is deprected, use std::ofstream instead.

--- src/mongo/shell/shell_utils_extended.cpp.orig	2023-06-29 02:35:52.000000000 +0000
+++ src/mongo/shell/shell_utils_extended.cpp
@@ -318,7 +318,7 @@ BSONObj writeFile(const BSONObj& args, v
             mode |= std::ios::binary;
     }
 
-    boost::filesystem::ofstream ofs{normalizedFilePath, mode};
+    std::ofstream ofs{normalizedFilePath.string(), mode};
     uassert(40346,
             str::stream() << "failed to open file " << normalizedFilePath.string()
                           << " for writing",
@@ -382,7 +382,7 @@ BSONObj readDumpFile(const BSONObj& a, v
 
     // Open the file for reading in binary mode.
     const auto pathStr = a.firstElement().String();
-    boost::filesystem::ifstream stream(pathStr, std::ios::in | std::ios::binary);
+    ifstream stream(pathStr, std::ios::in | std::ios::binary);
     uassert(31405,
             str::stream() << "readDumpFile(): Unable to open file \"" << pathStr
                           << "\" for reading",
