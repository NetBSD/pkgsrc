$NetBSD: patch-tests_Imap_test__Imap__BodyParts.cpp,v 1.1 2025/10/15 16:20:05 hauke Exp $

Duplicate declaration.

--- tests/Imap/test_Imap_BodyParts.cpp.orig	2025-10-15 15:25:49.795007647 +0000
+++ tests/Imap/test_Imap_BodyParts.cpp
@@ -51,6 +51,7 @@ struct Data {
 
 Q_DECLARE_METATYPE(QList<Data>)
 
+#if 0           /* Already declared in QtTest/qtest.h */
 namespace QTest {
 template <>
 char *toString(const QModelIndex &index)
@@ -60,6 +61,7 @@ char *toString(const QModelIndex &index)
     return qstrdup(buf.toUtf8().constData());
 }
 }
+#endif
 
 using namespace Imap::Mailbox;
 
