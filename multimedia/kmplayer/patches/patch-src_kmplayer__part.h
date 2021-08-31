$NetBSD: patch-src_kmplayer__part.h,v 1.1 2021/08/31 12:06:22 markd Exp $

From 3def65075c09af4961cd399e8e78ed78cca72e65 Mon Sep 17 00:00:00 2001
From: Wolfgang Bauer <wbauer@tmo.at>
Date: Wed, 11 Oct 2017 22:16:02 +0200
Subject: [PATCH] Fix build with Qt 5.9

Summary:
moc 5.9 errors out when building:
Error: Plugin Metadata file "" could not be opened: file to open is a directory

Same issue and fix as https://phabricator.kde.org/D5392 for khtml.

CCBUG: 377490

Test Plan: builds fine now with Qt 5.9.0rc and also earlier versions.

Reviewers: vriezen, pino

Reviewed By: pino

Subscribers: pino

Differential Revision: https://phabricator.kde.org/D5985
---
 src/kmplayer_part.h | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/src/kmplayer_part.h b/src/kmplayer_part.h
index f90f85d1..0fddbaa1 100644
--- src/kmplayer_part.h
+++ src/kmplayer_part.h
@@ -36,7 +36,7 @@ namespace KMPlayer {
 
 class KMPlayerFactory : public KPluginFactory {
     Q_OBJECT
-    Q_PLUGIN_METADATA(IID "org.kde.KPluginFactory" FILE "")
+    Q_PLUGIN_METADATA(IID "org.kde.KPluginFactory")
     Q_INTERFACES(KPluginFactory)
 public:
     KMPlayerFactory();
-- 
GitLab

