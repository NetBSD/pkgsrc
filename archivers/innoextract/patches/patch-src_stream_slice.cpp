$NetBSD: patch-src_stream_slice.cpp,v 1.2 2025/01/22 12:47:49 wiz Exp $

Fix build with newer boost.
https://github.com/dscharrer/innoextract/commit/264c2fe6b84f90f6290c670e5f676660ec7b2387

--- src/stream/slice.cpp.orig	2024-04-21 16:03:13.394516482 +0000
+++ src/stream/slice.cpp
@@ -26,6 +26,7 @@
 
 #include <boost/cstdint.hpp>
 #include <boost/algorithm/string/predicate.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/range/size.hpp>
 
