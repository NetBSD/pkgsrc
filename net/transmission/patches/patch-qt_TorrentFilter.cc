$NetBSD: patch-qt_TorrentFilter.cc,v 1.1 2020/07/22 13:25:40 wiz Exp $

Remove unneeded header that breaks build on NetBSD 8.

--- qt/TorrentFilter.cc.orig	2020-05-22 11:04:23.458805360 +0000
+++ qt/TorrentFilter.cc
@@ -7,7 +7,6 @@
  */
 
 #include <algorithm>
-#include <optional>
 
 #include "Filters.h"
 #include "Prefs.h"
