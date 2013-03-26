$NetBSD: patch-karm_task.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- karm/task.h.orig	2013-03-26 10:11:16.000000000 +0000
+++ karm/task.h
@@ -21,8 +21,10 @@ class QString;
 class KarmStorage;
 
 class QTimer;
-class KCal::Incidence;
-class KCal::Todo;
+namespace KCal {
+    class Incidence;
+    class Todo;
+}
 class QObject;
 class QPixmap;
 
