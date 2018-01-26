$NetBSD: patch-src_core_CLucene_queryParser_QueryParser.h,v 1.1 2018/01/26 15:27:04 jperkin Exp $

Fix -Wc++11-narrowing.

--- src/core/CLucene/queryParser/QueryParser.h.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/core/CLucene/queryParser/QueryParser.h
@@ -477,8 +477,8 @@ private:
   bool jj_semLA;
   int32_t jj_gen;
   int32_t jj_la1[23];
-  static const int32_t jj_la1_0[];
-  static const int32_t jj_la1_1[];
+  static const uint32_t jj_la1_0[];
+  static const uint32_t jj_la1_1[];
   JJCalls* jj_2_rtns;
   bool jj_rescan;
   int32_t jj_gc;
