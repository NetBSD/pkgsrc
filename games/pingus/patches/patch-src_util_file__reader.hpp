$NetBSD: patch-src_util_file__reader.hpp,v 1.1 2019/12/19 22:15:10 joerg Exp $

--- src/util/file_reader.hpp.orig	2019-12-19 20:16:23.201191068 +0000
+++ src/util/file_reader.hpp
@@ -18,6 +18,7 @@
 #define HEADER_PINGUS_UTIL_FILE_READER_HPP
 
 #include <memory>
+#include <string>
 #include <vector>
 
 class Size;
