$NetBSD: patch-src_pingus_pingus__level.hpp,v 1.1 2019/12/19 22:15:10 joerg Exp $

--- src/pingus/pingus_level.hpp.orig	2019-12-19 20:15:26.796566528 +0000
+++ src/pingus/pingus_level.hpp
@@ -18,6 +18,7 @@
 #define HEADER_PINGUS_PINGUS_PINGUS_LEVEL_HPP
 
 #include <map>
+#include <string>
 
 #include "util/file_reader.hpp"
 
