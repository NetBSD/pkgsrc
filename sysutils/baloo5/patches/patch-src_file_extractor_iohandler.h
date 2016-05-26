$NetBSD: patch-src_file_extractor_iohandler.h,v 1.1 2016/05/26 09:17:14 markd Exp $

Don't clash with stdio defines

--- src/file/extractor/iohandler.h.orig	2016-04-03 20:42:08.000000000 +0000
+++ src/file/extractor/iohandler.h
@@ -31,7 +31,7 @@ namespace Baloo {
 class IOHandler
 {
 public:
-    IOHandler(int stdin, int stdout);
+    IOHandler(int StdIn, int StdOut);
     quint64 nextId();
     bool atEnd() const;
 
