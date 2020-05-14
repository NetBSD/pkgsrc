$NetBSD: patch-src_insert__completer.cc,v 1.1 2020/05/14 19:06:55 joerg Exp $

--- src/insert_completer.cc.orig	2020-05-11 00:26:58.591197327 +0000
+++ src/insert_completer.cc
@@ -15,7 +15,7 @@
 #include "option_types.hh"
 #include "utf8_iterator.hh"
 #include "user_interface.hh"
-
+#include "ranges.hh"
 #include <numeric>
 #include <utility>
 
@@ -119,7 +119,7 @@ InsertCompletion complete_word(const Sel
     auto& word_db = get_word_db(buffer);
     Vector<RankedMatchAndBuffer> matches = word_db.find_matching(prefix)
                                          | transform([&](auto& m) { return RankedMatchAndBuffer{m, &buffer}; })
-                                         | gather<Vector>();
+                                         | gather<Vector<RankedMatchAndBuffer>>();
     // Remove words that are being edited
     for (auto& word_count : sel_word_counts)
     {
