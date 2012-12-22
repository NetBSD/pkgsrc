$NetBSD: patch-libktcore_groups_torrentgroup.h,v 1.1 2012/12/22 20:02:37 joerg Exp $

--- libktcore/groups/torrentgroup.h.orig	2012-12-22 19:31:00.000000000 +0000
+++ libktcore/groups/torrentgroup.h
@@ -29,7 +29,6 @@ namespace kt
 {
 
 	class QueueManager;
-	class TorrentInterface;
 
 	/**
 		@author Joris Guisson <joris.guisson@gmail.com>
