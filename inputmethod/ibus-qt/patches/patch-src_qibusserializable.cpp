$NetBSD: patch-src_qibusserializable.cpp,v 1.2 2014/04/30 06:53:19 obache Exp $

* http://code.google.com/p/ibus/issues/detail?id=1706

--- src/qibusserializable.cpp.orig	2012-11-19 16:47:11.000000000 +0000
+++ src/qibusserializable.cpp
@@ -25,7 +25,7 @@ Serializable::getAttachment (const QStri
 SerializablePointer
 Serializable::removeAttachment (const QString &key)
 {
-    SerializablePointer p = m_attachments.value (key, p);
+    SerializablePointer p = m_attachments.value (key);
     if (p)
         m_attachments.remove (key);
     return p;
