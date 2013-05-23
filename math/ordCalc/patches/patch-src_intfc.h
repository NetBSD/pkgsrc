$NetBSD: patch-src_intfc.h,v 1.1 2013/05/23 18:41:21 joerg Exp $

--- src/intfc.h.orig	2013-05-23 17:23:47.000000000 +0000
+++ src/intfc.h
@@ -170,7 +170,7 @@ public:
         
     void parseInput(const char * file);
     void popFile();
-    void readline(char * buf, int& char_read, int max_size);
+    void readline(char * buf, size_t& char_read, int max_size);
     void readFromFile(const string * fileName);
     void readFromFile();
     enum logOption {createLog,flushLog,stopLog,exitClean};
