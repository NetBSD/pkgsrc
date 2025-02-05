$NetBSD: patch-src_libdbusmenu-qt_dbusmenushortcut__p.h,v 1.1 2025/02/05 22:25:38 markd Exp $

* Add DBusMenuShortcut type overload for QDBusArgument to fix build

--- src/libdbusmenu-qt/dbusmenushortcut_p.h.orig	2025-01-04 08:49:00.488996262 +0000
+++ src/libdbusmenu-qt/dbusmenushortcut_p.h
@@ -12,6 +12,7 @@
 #include <QStringList>
 
 class QKeySequence;
+class QDBusArgument;
 
 class DBusMenuShortcut : public QList<QStringList>
 {
@@ -20,6 +21,9 @@ public:
     static DBusMenuShortcut fromKeySequence(const QKeySequence &);
 };
 
+QDBusArgument &operator<<(QDBusArgument &argument, const DBusMenuShortcut &);
+const QDBusArgument &operator>>(const QDBusArgument &argument, DBusMenuShortcut &);
+
 Q_DECLARE_METATYPE(DBusMenuShortcut)
 
 #endif /* DBUSMENUSHORTCUT_H */
