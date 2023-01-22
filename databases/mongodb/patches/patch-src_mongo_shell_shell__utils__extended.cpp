$NetBSD: patch-src_mongo_shell_shell__utils__extended.cpp,v 1.1 2023/01/22 17:36:31 ryoon Exp $

* boost::filesystem::ofstream deprected, use std::ofstream instead.

--- src/mongo/shell/shell_utils_extended.cpp.orig	2021-06-30 17:39:08.000000000 +0000
+++ src/mongo/shell/shell_utils_extended.cpp
@@ -318,7 +318,7 @@ BSONObj writeFile(const BSONObj& args, v
             mode |= std::ios::binary;
     }
 
-    boost::filesystem::ofstream ofs{normalizedFilePath, mode};
+    std::ofstream ofs{normalizedFilePath, mode};
     uassert(40346,
             str::stream() << "failed to open file " << normalizedFilePath.string()
                           << " for writing",
