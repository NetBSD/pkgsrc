$NetBSD: patch-lang_qt_src_threadedjobmixin.cpp,v 1.1 2024/03/11 11:04:49 jperkin Exp $

Avoid "single" conflict.

--- lang/qt/src/threadedjobmixin.cpp.orig	2024-03-11 11:01:40.762774232 +0000
+++ lang/qt/src/threadedjobmixin.cpp
@@ -119,7 +119,7 @@ static QList<QByteArray> from_sl(const Q
     return result;
 }
 
-static QList<QByteArray> single(const QByteArray &ba)
+static QList<QByteArray> push_single(const QByteArray &ba)
 {
     QList<QByteArray> result;
     result.push_back(ba);
@@ -127,9 +127,9 @@ static QList<QByteArray> single(const QB
 }
 
 _detail::PatternConverter::PatternConverter(const QByteArray &ba)
-    : m_list(single(ba)), m_patterns(nullptr) {}
+    : m_list(push_single(ba)), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QString &s)
-    : m_list(single(s.toUtf8())), m_patterns(nullptr) {}
+    : m_list(push_single(s.toUtf8())), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QList<QByteArray> &lba)
     : m_list(lba), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QStringList &sl)
