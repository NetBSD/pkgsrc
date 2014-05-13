$NetBSD: patch-src_context.cpp,v 1.1 2014/05/13 15:31:40 sborrill Exp $

Don't force configuration files to be relative to cwd

--- src/context.cpp.orig	2014-05-13 16:06:05.000000000 +0100
+++ src/context.cpp	2014-05-13 16:08:21.000000000 +0100
@@ -445,7 +445,14 @@
 void WHITELISTER::merge() {
     time_t now = time(NULL);
     ifstream ifs;
-    ifs.open(fn);
+
+    if (fn[0] != '/') {
+        string fullpath("@CONFDIR@");
+        fullpath += "/";
+        fullpath += fn;
+        ifs.open(fullpath.c_str());
+    } else
+        ifs.open(fn);              
     if (!ifs.fail()) {
         const int maxlen = 1000;
         char buf[maxlen];
