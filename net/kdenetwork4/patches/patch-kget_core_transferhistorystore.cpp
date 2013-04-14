$NetBSD: patch-kget_core_transferhistorystore.cpp,v 1.1 2013/04/14 19:44:54 joerg Exp $

Deal with the vexing parse issue.

--- kget/core/transferhistorystore.cpp.orig	2013-04-14 16:30:38.000000000 +0000
+++ kget/core/transferhistorystore.cpp
@@ -554,7 +554,7 @@ NepomukStore::~NepomukStore()
 void NepomukStore::load()
 {
     Nepomuk::Query::QueryServiceClient * queryService = new Nepomuk::Query::QueryServiceClient(this);
-    Nepomuk::Query::ResourceTypeTerm historyTypeTerm(Nepomuk::Types::Class(Nepomuk::HistoryItem::resourceTypeUri()));
+    Nepomuk::Query::ResourceTypeTerm historyTypeTerm((Nepomuk::Types::Class(Nepomuk::HistoryItem::resourceTypeUri())));
     Nepomuk::Query::Query historyQuery(historyTypeTerm);
 
     connect(queryService, SIGNAL(newEntries(const QList<Nepomuk::Query::Result>&)), this, SLOT(loadResult(const QList<Nepomuk::Query::Result>&)));
