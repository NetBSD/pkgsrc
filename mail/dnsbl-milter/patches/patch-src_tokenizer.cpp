$NetBSD: patch-src_tokenizer.cpp,v 1.1 2014/05/13 15:31:40 sborrill Exp $

Don't force configuration files to be relative to cwd

--- src/tokenizer.cpp.orig	2014-02-05 15:55:12.000000000 +0000
+++ src/tokenizer.cpp	2014-05-13 16:05:49.000000000 +0100
@@ -346,7 +346,13 @@
         return false;
     }
     ifstream *is = new ifstream;
-    is->open(fn);
+    if (fn[0] != '/') {
+    	string fullpath("@CONFDIR@");
+    	fullpath += "/";
+    	fullpath += fn;
+    	is->open(fullpath.c_str());
+    } else
+    	is->open(fn);
     if (is->fail()) {
         char buf[maxlen];
         snprintf(buf, sizeof(buf), "include file %s not found", fn);
