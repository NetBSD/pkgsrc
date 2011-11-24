$NetBSD: patch-src_file_GZFileAdapter.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/file/GZFileAdapter.cc.orig	2011-11-24 02:43:36.000000000 +0000
+++ src/file/GZFileAdapter.cc
@@ -3,6 +3,7 @@
 #include "GZFileAdapter.hh"
 #include "FileException.hh"
 #include <cassert>
+#include <cstdlib>
 #include <zlib.h>
 
 namespace openmsx {
