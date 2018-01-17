$NetBSD: patch-src_file_extractor_iohandler.h,v 1.2 2018/01/17 20:09:33 markd Exp $

Don't use "stdin"

--- src/file/extractor/iohandler.h.orig	2017-12-02 20:01:27.000000000 +0000
+++ src/file/extractor/iohandler.h
@@ -31,7 +31,7 @@ namespace Baloo {
 class IOHandler
 {
 public:
-    IOHandler(int stdin);
+    IOHandler(int stdIn);
     quint64 nextId();
     bool atEnd() const;
 
