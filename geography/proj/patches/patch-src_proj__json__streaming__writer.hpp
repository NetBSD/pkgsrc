$NetBSD: patch-src_proj__json__streaming__writer.hpp,v 1.3 2024/06/10 09:41:52 jperkin Exp $

Fix C++ includes.

--- src/proj_json_streaming_writer.hpp.orig	2024-06-10 09:36:16.701451389 +0000
+++ src/proj_json_streaming_writer.hpp
@@ -31,6 +31,7 @@
 
 /*! @cond Doxygen_Suppress */
 
+#include <cstdint>
 #include <vector>
 #include <string>
 
