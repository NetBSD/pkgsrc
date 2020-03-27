$NetBSD: patch-src_common_types.h,v 1.1 2020/03/27 08:45:26 nia Exp $

Fix building with Qt>=5.14

https://github.com/quassel/quassel/pull/518

--- src/common/types.h.orig	2019-02-15 16:17:28.000000000 +0000
+++ src/common/types.h
@@ -140,6 +140,7 @@ Q_DECLARE_METATYPE(QHostAddress)
 typedef QList<MsgId> MsgIdList;
 typedef QList<BufferId> BufferIdList;
 
+#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
 /**
  * Catch-all stream serialization operator for enum types.
  *
@@ -169,6 +170,7 @@ QDataStream &operator>>(QDataStream &in,
     value = static_cast<T>(v);
     return in;
 }
+#endif
 
 // Exceptions
 
