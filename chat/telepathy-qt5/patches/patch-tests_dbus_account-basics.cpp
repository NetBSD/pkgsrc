$NetBSD: patch-tests_dbus_account-basics.cpp,v 1.1 2019/12/12 16:44:53 nros Exp $
* remove use of deprecated function
--- tests/dbus/account-basics.cpp.orig	2019-11-11 17:17:37.000000000 +0000
+++ tests/dbus/account-basics.cpp
@@ -295,15 +295,15 @@ void TestAccountBasics::testBasics()
         SimpleStatusSpec prSpec = { ConnectionPresenceTypeOffline, true, false };
         expectedPresences.append(PresenceSpec(QLatin1String("offline"), prSpec));
     }
-    qSort(expectedPresences);
+    std::sort(expectedPresences.begin(), expectedPresences.end());
 
     PresenceSpecList presences = acc->allowedPresenceStatuses(false);
-    qSort(presences);
+    std::sort(presences.begin(), presences.end());
     QCOMPARE(presences.size(), 2);
     QCOMPARE(presences, expectedPresences);
 
     presences = acc->allowedPresenceStatuses(true);
-    qSort(presences);
+    std::sort(presences.begin(), presences.end());
     QCOMPARE(presences.size(), 2);
     QCOMPARE(presences, expectedPresences);
 
@@ -491,10 +491,10 @@ void TestAccountBasics::testBasics()
         SimpleStatusSpec prSpec = { ConnectionPresenceTypeOffline, true, false };
         expectedPresences.append(PresenceSpec(QLatin1String("offline"), prSpec));
     }
-    qSort(expectedPresences);
+    std::sort(expectedPresences.begin(), expectedPresences.end());
 
     presences = acc->allowedPresenceStatuses(false);
-    qSort(presences);
+    std::sort(presences.begin(), presences.end());
     QCOMPARE(presences.size(), 3);
     QCOMPARE(presences, expectedPresences);
 
@@ -502,10 +502,10 @@ void TestAccountBasics::testBasics()
         SimpleStatusSpec prSpec = { ConnectionPresenceTypeExtendedAway, false, false };
         expectedPresences.append(PresenceSpec(QLatin1String("xa"), prSpec));
     }
-    qSort(expectedPresences);
+    std::sort(expectedPresences.begin(), expectedPresences.end());
 
     presences = acc->allowedPresenceStatuses(true);
-    qSort(presences);
+    std::sort(presences.begin(), presences.end());
     QCOMPARE(presences.size(), 4);
     QCOMPARE(presences, expectedPresences);
 
