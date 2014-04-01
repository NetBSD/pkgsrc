$NetBSD: patch-qt_torrent-filter.cc,v 1.1 2014/04/01 09:48:04 adam Exp $

Fix building error.

--- qt/torrent-filter.cc.orig	2014-04-01 07:01:04.000000000 +0000
+++ qt/torrent-filter.cc
@@ -211,7 +211,7 @@ TorrentFilter :: hiddenRowCount( ) const
 void
 TorrentFilter :: countTorrentsPerMode (int * setmeCounts) const
 {
-  std::fill_n (setmeCounts, FilterMode::NUM_MODES, 0);
+  std::fill_n (setmeCounts, (int)FilterMode::NUM_MODES, 0);
 
   for (int row(0); ; ++row)
     { 
