$NetBSD: patch-server_tests_unittest_partstreamertest.cpp,v 1.1 2016/01/10 19:40:30 markd Exp $

From: Dan Vrátil <dvratil@redhat.com>
Date: Mon, 29 Jun 2015 20:45:11 +0000
Subject: Don't leak old external payload files
X-Git-Url: http://quickgit.kde.org/?p=akonadi.git&a=commitdiff&h=9c0dc6b3f0826d32eac310b2e7ecd858ca3df681
---
Don't leak old external payload files

Actually delete old payload files after we increase the payload revision or
switch from external to internal payload. This caused ~/.local/share/akonadi/file_db_data
to grow insanely for all users, leaving them with many duplicated files (just with
different revisions).

It is recommended that users run akonadictl fsck to clean up the leaked payload
files.

Note that there won't be any more releases of Akonadi 1.13 (and this has been
fixed in master already), so I strongly recommend distributions to pick this
patch into their packaging.

BUG: 341884
CCBUG: 338402
--- server/tests/unittest/partstreamertest.cpp.orig	2014-08-10 10:38:58.000000000 +0000
+++ server/tests/unittest/partstreamertest.cpp
@@ -91,6 +91,7 @@ private Q_SLOTS:
         QTest::addColumn<qint64>("expectedPartSize");
         QTest::addColumn<bool>("expectedChanged");
         QTest::addColumn<bool>("isExternal");
+        QTest::addColumn<int>("version");
         QTest::addColumn<PimItem>("pimItem");
 
         PimItem item;
@@ -101,13 +102,12 @@ private Q_SLOTS:
         QVERIFY(item.insert());
 
         // Order of these tests matters!
-        QTest::newRow("item 1, internal") << QByteArray("PLD:DATA") << QByteArray("123") << 3ll << true << false << item;
-        QTest::newRow("item 1, change to external") << QByteArray("PLD:DATA") << QByteArray("123456789") << 9ll << true << true << item;
-        QTest::newRow("item 1, update external") << QByteArray("PLD:DATA") << QByteArray("987654321") << 9ll << true << true << item;
-        QTest::newRow("item 1, external, no change") << QByteArray("PLD:DATA") << QByteArray("987654321") << 9ll << false << true << item;
-        QTest::newRow("item 1, change to internal") << QByteArray("PLD:DATA") << QByteArray("1234") << 4ll << true << false << item;
-        QTest::newRow("item 1, internal, no change") << QByteArray("PLD:DATA") << QByteArray("1234") << 4ll << false << false << item;
-    }
+        QTest::newRow("item 1, internal") << QByteArray("PLD:DATA") << QByteArray("123") << 3ll << true << false << -1 << item;
+        QTest::newRow("item 1, change to external") << QByteArray("PLD:DATA") << QByteArray("123456789") << 9ll << true << true << 0 << item;
+        QTest::newRow("item 1, update external") << QByteArray("PLD:DATA") << QByteArray("987654321") << 9ll << true << true << 1 << item;
+        QTest::newRow("item 1, external, no change") << QByteArray("PLD:DATA") << QByteArray("987654321") << 9ll << false << true << 2 << item;
+        QTest::newRow("item 1, change to internal") << QByteArray("PLD:DATA") << QByteArray("1234") << 4ll << true << false << 2 << item;
+        QTest::newRow("item 1, internal, no change") << QByteArray("PLD:DATA") << QByteArray("1234") << 4ll << false << false << 2 << item;    }
 
     void testStreamer()
     {
@@ -117,6 +117,7 @@ private Q_SLOTS:
         QFETCH(qint64, expectedPartSize);
         QFETCH(bool, expectedChanged);
         QFETCH(bool, isExternal);
+        QFETCH(int, version);
         QFETCH(PimItem, pimItem);
 
         FakeConnection connection;
@@ -160,17 +161,18 @@ private Q_SLOTS:
 
         PimItem item = PimItem::retrieveById(pimItem.id());
         const QVector<Part> parts = item.parts();
-        QVERIFY(parts.count() == 1);
+        QCOMPARE(parts.count(), 1);
         const Part part = parts[0];
         QCOMPARE(part.datasize(), expectedPartSize);
         QCOMPARE(part.external(), isExternal);
+        qDebug() << part.version() << part.data();
         const QByteArray data = part.data();
         if (isExternal) {
             QVERIFY(streamerSpy.count() == 1);
             QVERIFY(streamerSpy.first().count() == 1);
             const Response response = streamerSpy.first().first().value<Akonadi::Server::Response>();
             const QByteArray str = response.asString();
-            const QByteArray expectedResponse = "+ STREAM [FILE " + QByteArray::number(part.id()) + "_r" + QByteArray::number(part.version()) + "]";
+            const QByteArray expectedResponse = "+ STREAM [FILE " + QByteArray::number(part.id()) + "_r" + QByteArray::number(version) + "]";
             QCOMPARE(QString::fromUtf8(str), QString::fromUtf8(expectedResponse));
 
             QFile file(PartHelper::resolveAbsolutePath(data));
@@ -182,7 +184,7 @@ private Q_SLOTS:
             QCOMPARE(fileData, expectedData);
 
             // Make sure no previous versions are left behind in file_db_data
-            for (int i = 0; i < part.version(); ++i) {
+            for (int i = 0; i < version; ++i) {
                 const QByteArray fileName = QByteArray::number(part.id()) + "_r" + QByteArray::number(part.version());
                 const QString filePath = PartHelper::resolveAbsolutePath(fileName);
                 QVERIFY(!QFile::exists(filePath));
@@ -194,7 +196,7 @@ private Q_SLOTS:
             QCOMPARE(data, expectedData);
 
             // Make sure nothing is left behind in file_db_data
-            for (int i = 0; i <= part.version(); ++i) {
+            for (int i = 0; i <= version; ++i) {
                 const QByteArray fileName = QByteArray::number(part.id()) + "_r" + QByteArray::number(part.version());
                 const QString filePath = PartHelper::resolveAbsolutePath(fileName);
                 QVERIFY(!QFile::exists(filePath));
