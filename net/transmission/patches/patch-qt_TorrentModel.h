$NetBSD: patch-qt_TorrentModel.h,v 1.1 2020/07/22 13:25:40 wiz Exp $

Remove unneeded header that breaks build on NetBSD 8.

--- qt/TorrentModel.h.orig	2020-05-22 11:04:23.458805360 +0000
+++ qt/TorrentModel.h
@@ -8,7 +8,6 @@
 
 #pragma once
 
-#include <optional>
 #include <vector>
 
 #include <QAbstractListModel>
