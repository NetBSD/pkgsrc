$NetBSD: patch-src_Sigil_SourceUpdates_WordUpdates.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/SourceUpdates/WordUpdates.cpp.orig	2016-01-12 20:32:16.000000000 +0000
+++ src/Sigil/SourceUpdates/WordUpdates.cpp
@@ -29,6 +29,8 @@
 #include "ResourceObjects/HTMLResource.h"
 #include "SourceUpdates/WordUpdates.h"
 
+using namespace boost::placeholders;
+
 void WordUpdates::UpdateWordInAllFiles(const QList<HTMLResource *> &html_resources, const QString old_word, QString new_word)
 {
     QtConcurrent::blockingMap(html_resources, boost::bind(UpdateWordsInOneFile, _1, old_word, new_word));
