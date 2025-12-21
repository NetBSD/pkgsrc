$NetBSD: patch-src_agentbase_agentbase.cpp,v 1.1 2025/12/21 12:56:08 markd Exp $

Check if QNetworkInformation::loadBackendByFeatures is successful otherwise
avoid nullptr access  -- from OpenBSD

--- src/agentbase/agentbase.cpp.orig	2025-10-06 03:29:54.000000000 +0000
+++ src/agentbase/agentbase.cpp
@@ -720,7 +720,7 @@ void AgentBasePrivate::slotNetworkStatus
 
 void AgentBasePrivate::slotResumedFromSuspend()
 {
-    if (mNeedsNetwork) {
+    if (mNeedsNetwork && QNetworkInformation::instance()) {
         slotNetworkStatusChange(QNetworkInformation::instance()->reachability() != QNetworkInformation::Reachability::Online);
     }
 }
@@ -904,10 +904,11 @@ void AgentBase::setNeedsNetwork(bool nee
     }
 
     d->mNeedsNetwork = needsNetwork;
-    QNetworkInformation::loadBackendByFeatures(QNetworkInformation::Feature::Reachability);
-    connect(QNetworkInformation::instance(), &QNetworkInformation::reachabilityChanged, this, [d](auto reachability) {
-        d->slotNetworkStatusChange(reachability == QNetworkInformation::Reachability::Online);
-    });
+    if (QNetworkInformation::loadBackendByFeatures(QNetworkInformation::Feature::Reachability)) {
+         connect(QNetworkInformation::instance(), &QNetworkInformation::reachabilityChanged, this, [d](auto reachability) {
+                 d->slotNetworkStatusChange(reachability == QNetworkInformation::Reachability::Online);
+                 });
+    }
 }
 
 void AgentBase::setOnline(bool state)
@@ -950,7 +951,7 @@ void AgentBase::setTemporaryOffline(int 
 void AgentBase::setOnlineInternal(bool state)
 {
     Q_D(AgentBase);
-    if (state && d->mNeedsNetwork) {
+    if (state && d->mNeedsNetwork && QNetworkInformation::instance()) {
         if (QNetworkInformation::instance()->reachability() != QNetworkInformation::Reachability::Online) {
             // Don't go online if the resource needs network but there is none
             state = false;
