$NetBSD: patch-libstreamanalyzer_plugins_indexers_clucenengindexer_cluceneindexreader.cpp,v 1.1 2016/07/16 04:47:45 markd Exp $

Build with gcc 6

--- libstreamanalyzer/plugins/indexers/clucenengindexer/cluceneindexreader.cpp.orig	2013-02-05 21:34:52.000000000 +0000
+++ libstreamanalyzer/plugins/indexers/clucenengindexer/cluceneindexreader.cpp
@@ -321,7 +321,7 @@ CLuceneIndexReader::Private::addField(lu
         string size = value;
         doc.size = atoi(size.c_str());
     } else {
-        doc.properties.insert(make_pair<const string, string>(
+        doc.properties.insert(make_pair<const string, string&>(
             wchartoutf8(name), value));
     }
 }
