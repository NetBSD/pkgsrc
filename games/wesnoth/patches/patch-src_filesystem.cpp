$NetBSD: patch-src_filesystem.cpp,v 1.1 2024/05/15 11:22:50 wiz Exp $

Fix build with boost 1.85.
https://github.com/wesnoth/wesnoth/commit/55162c465405d55f03be0f89daf16818c552d506

--- src/filesystem.cpp.orig	2024-05-15 10:55:40.456101659 +0000
+++ src/filesystem.cpp
@@ -30,6 +30,7 @@
 #include "serialization/unicode.hpp"
 #include "utils/general.hpp"
 
+#include <boost/filesystem.hpp>
 #include <boost/filesystem/fstream.hpp>
 #include <boost/iostreams/device/file_descriptor.hpp>
 #include <boost/iostreams/stream.hpp>
