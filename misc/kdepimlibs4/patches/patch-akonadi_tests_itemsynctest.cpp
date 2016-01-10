$NetBSD: patch-akonadi_tests_itemsynctest.cpp,v 1.1 2016/01/10 19:33:04 markd Exp $

kdepimlibs4-bug338658-[12].patch
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=4429619&o=plain
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=d8b5da7&o=plain

--- akonadi/tests/itemsynctest.cpp.orig	2015-06-24 12:43:14.000000000 +0000
+++ akonadi/tests/itemsynctest.cpp
@@ -438,14 +438,19 @@ class ItemsyncTest : public QObject
        AKVERIFYEXEC(syncer);
 
        Item::List resultItems = fetchItems(col);
-       QCOMPARE(resultItems.count(), 2);
+       QCOMPARE(resultItems.count(), 3);
 
-       ItemFetchJob *fetchJob = new ItemFetchJob(modifiedItem);
+       Item item;
+       item.setGid(QLatin1String("gid2"));
+       ItemFetchJob *fetchJob = new ItemFetchJob(item);
        fetchJob->fetchScope().fetchFullPayload();
        AKVERIFYEXEC(fetchJob);
-       QCOMPARE(fetchJob->items().size(), 1);
+       QCOMPARE(fetchJob->items().size(), 2);
        QCOMPARE(fetchJob->items().first().payload<QByteArray>(), QByteArray("payload2"));
        QCOMPARE(fetchJob->items().first().remoteId(), QString::fromLatin1("rid3"));
+       QCOMPARE(fetchJob->items().first().remoteId(), QLatin1String("rid3"));
+       QCOMPARE(fetchJob->items().at(1).payload<QByteArray>(), QByteArray("payload1"));
+       QCOMPARE(fetchJob->items().at(1).remoteId(), QLatin1String("rid2"));
     }
 
     /*
