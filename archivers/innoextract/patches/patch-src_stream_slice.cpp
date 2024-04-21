$NetBSD: patch-src_stream_slice.cpp,v 1.1 2024/04/21 16:08:30 adam Exp $

Fix build with newer boost.

--- src/stream/slice.cpp.orig	2024-04-21 16:03:13.394516482 +0000
+++ src/stream/slice.cpp
@@ -26,6 +26,7 @@
 
 #include <boost/cstdint.hpp>
 #include <boost/algorithm/string/predicate.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/range/size.hpp>
 
