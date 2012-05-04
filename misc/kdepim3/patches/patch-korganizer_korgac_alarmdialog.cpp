$NetBSD: patch-korganizer_korgac_alarmdialog.cpp,v 1.1 2012/05/04 16:27:59 joerg Exp $

--- korganizer/korgac/alarmdialog.cpp.orig	2012-04-27 16:49:30.000000000 +0000
+++ korganizer/korgac/alarmdialog.cpp
@@ -324,9 +324,9 @@ void AlarmDialog::eventNotification()
     found = true;
     item->mNotified = true;
     Alarm::List alarms = item->mIncidence->alarms();
-    Alarm::List::ConstIterator it;
-    for ( it = alarms.begin(); it != alarms.end(); ++it ) {
-      Alarm *alarm = *it;
+    Alarm::List::ConstIterator it2;
+    for ( it2 = alarms.begin(); it2 != alarms.end(); ++it2 ) {
+      Alarm *alarm = *it2;
       // FIXME: Check whether this should be done for all multiple alarms
       if (alarm->type() == Alarm::Procedure) {
         // FIXME: Add a message box asking whether the procedure should really be executed
