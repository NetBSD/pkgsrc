$NetBSD: patch-js_src_gc_Statistics.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/gc/Statistics.cpp.orig	2015-02-05 11:52:40.000000000 +0000
+++ js/src/gc/Statistics.cpp	2015-02-05 11:52:28.000000000 +0000
@@ -221,8 +221,8 @@
         while (*c) {
             if (*c == ' ' || *c == '\t')
                 p('_');
-            else if (isupper(*c))
-                p(tolower(*c));
+            else if (isupper((unsigned char)*c))
+                p(tolower((unsigned char)*c));
             else if (*c == '+')
                 p("added_");
             else if (*c == '-')
