$NetBSD: patch-tests_dbus_client.cpp,v 1.1 2019/12/12 16:44:53 nros Exp $
* remove use of deprecated function
--- tests/dbus/client.cpp.orig	2019-11-11 17:17:37.000000000 +0000
+++ tests/dbus/client.cpp
@@ -753,12 +753,12 @@ void TestClient::testAddDispatchOperatio
     handledChannels.clear();
     QVERIFY(waitForProperty(handler1Iface->requestPropertyHandledChannels(), &handledChannels));
     QVERIFY(!handledChannels.isEmpty());
-    qSort(handledChannels);
+    std::sort(handledChannels.begin(), handledChannels.end());
     Tp::ObjectPathList expectedHandledChannels;
     Q_FOREACH (const ChannelDetails &details, mCDO->Channels()) {
         expectedHandledChannels << details.channel;
     }
-    qSort(expectedHandledChannels);
+    std::sort(expectedHandledChannels.begin(), expectedHandledChannels.end());
     QCOMPARE(handledChannels, expectedHandledChannels);
 }
 
