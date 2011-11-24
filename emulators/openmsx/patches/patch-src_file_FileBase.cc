$NetBSD: patch-src_file_FileBase.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/file/FileBase.cc.orig	2011-11-24 02:43:13.000000000 +0000
+++ src/file/FileBase.cc
@@ -2,6 +2,7 @@
 
 #include "FileBase.hh"
 #include <algorithm>
+#include <cstring>
 
 using std::string;
 
