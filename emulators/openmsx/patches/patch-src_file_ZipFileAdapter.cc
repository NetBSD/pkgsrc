$NetBSD: patch-src_file_ZipFileAdapter.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/file/ZipFileAdapter.cc.orig	2011-11-24 02:43:55.000000000 +0000
+++ src/file/ZipFileAdapter.cc
@@ -3,6 +3,7 @@
 #include <zlib.h>
 #include "ZipFileAdapter.hh"
 #include "FileException.hh"
+#include <cstdlib>
 
 namespace openmsx {
 
