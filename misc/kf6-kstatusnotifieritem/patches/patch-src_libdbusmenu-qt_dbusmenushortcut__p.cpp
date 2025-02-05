$NetBSD: patch-src_libdbusmenu-qt_dbusmenushortcut__p.cpp,v 1.1 2025/02/05 22:25:38 markd Exp $

* Add DBusMenuShortcut type overload for QDBusArgument to fix build

--- src/libdbusmenu-qt/dbusmenushortcut_p.cpp.orig	2025-01-04 08:49:06.219623820 +0000
+++ src/libdbusmenu-qt/dbusmenushortcut_p.cpp
@@ -8,6 +8,8 @@
 
 // Qt
 #include <QKeySequence>
+#include <QDBusArgument>
+#include <QDBusMetaType>
 
 // Local
 #include "debug_p.h"
@@ -70,3 +72,28 @@ QKeySequence DBusMenuShortcut::toKeySequ
     const QString string = tmp.join(QLatin1String(", "));
     return QKeySequence::fromString(string);
 }
+
+QDBusArgument &operator<<(QDBusArgument &argument, const DBusMenuShortcut &obj)
+{
+    argument.beginArray(qMetaTypeId<QStringList>());
+    typename QList<QStringList>::ConstIterator it = obj.constBegin();
+    typename QList<QStringList>::ConstIterator end = obj.constEnd();
+    for ( ; it != end; ++it)
+        argument << *it;
+    argument.endArray();
+    return argument;
+}
+
+const QDBusArgument &operator>>(const QDBusArgument &argument, DBusMenuShortcut &obj)
+{
+    argument.beginArray();
+    obj.clear();
+    while (!argument.atEnd()) {
+        QStringList item;
+        argument >> item;
+        obj.push_back(item);
+    }
+    argument.endArray();
+    return argument;
+}
+
