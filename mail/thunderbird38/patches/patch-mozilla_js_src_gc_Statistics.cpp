$NetBSD: patch-mozilla_js_src_gc_Statistics.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/js/src/gc/Statistics.cpp.orig	2015-06-08 17:49:22.000000000 +0000
+++ mozilla/js/src/gc/Statistics.cpp
@@ -222,8 +222,8 @@ class gcstats::StatisticsSerializer
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
