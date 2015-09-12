$NetBSD: patch-src_engine_shared_storage.cpp,v 1.1 2015/09/12 18:53:17 wiz Exp $

==========================================================
This patch adds /usr/pkg as one of the default directories
to search for data files in 

pkglint is concerned about the absolute pathnames in this patch:
WARN: [...] Found absolute pathname: /usr/pkg/share/teeworlds/data
WARN: [...] Found absolute pathname: /usr/pkg/share/games/teeworlds/data
But I believe there's nothing we can do about it here.

This patch has been submitted upstream.
https://github.com/teeworlds/teeworlds/pull/1397
==========================================================


--- src/engine/shared/storage.cpp.orig	2015-09-12 14:30:15.000000000 +0200
+++ src/engine/shared/storage.cpp	2015-09-12 14:23:49.000000000 +0200
@@ -211,6 +211,8 @@
 				"/usr/share/games/teeworlds/data",
 				"/usr/local/share/teeworlds/data",
 				"/usr/local/share/games/teeworlds/data",
+				"/usr/pkg/share/teeworlds/data",
+				"/usr/pkg/share/games/teeworlds/data",
 				"/opt/teeworlds/data"
 			};
 			const int DirsCount = sizeof(aDirs) / sizeof(aDirs[0]);
