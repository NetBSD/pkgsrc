$NetBSD: patch-src_proj__json__streaming__writer.hpp,v 1.1 2023/08/27 09:16:56 tnn Exp $

https://github.com/OSGeo/PROJ/commit/b0b8937c56ced8eb0ffef532b9c691a1a5fc8634

--- src/proj_json_streaming_writer.hpp.orig	2020-01-23 08:45:49.000000000 +0000
+++ src/proj_json_streaming_writer.hpp
@@ -31,6 +31,7 @@
 
 /*! @cond Doxygen_Suppress */
 
+#include <cstdint>
 #include <vector>
 #include <string>
 
