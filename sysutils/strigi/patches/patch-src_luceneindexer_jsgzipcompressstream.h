$NetBSD: patch-src_luceneindexer_jsgzipcompressstream.h,v 1.2 2012/01/16 19:47:31 adam Exp $

Fix build with gcc4.3 and clang

--- src/luceneindexer/jsgzipcompressstream.h.orig	2009-02-01 19:55:38.000000000 +0000
+++ src/luceneindexer/jsgzipcompressstream.h
@@ -21,6 +21,8 @@
 #define GZIPCOMPRESSSTREAM_H
 
 #include <strigi/strigiconfig.h>   // (u)int64_t
+#include <cstdio>
+#include <cstring>
 #include <CLucene/util/streambase.h>
 #include <CLucene/util/bufferedstream.h>
 
