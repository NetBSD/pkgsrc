$NetBSD: patch-src_luceneindexer_jsgzipcompressstream.h,v 1.1 2011/02/17 09:45:00 markd Exp $

Fix build with gcc4.3

--- src/luceneindexer/jsgzipcompressstream.h.orig	2009-02-01 19:55:38.000000000 +0000
+++ src/luceneindexer/jsgzipcompressstream.h
@@ -21,6 +21,7 @@
 #define GZIPCOMPRESSSTREAM_H
 
 #include <strigi/strigiconfig.h>   // (u)int64_t
+#include <cstdio>
 #include <CLucene/util/streambase.h>
 #include <CLucene/util/bufferedstream.h>
 
