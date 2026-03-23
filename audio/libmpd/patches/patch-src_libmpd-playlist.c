$NetBSD: patch-src_libmpd-playlist.c,v 1.1 2026/03/23 13:07:51 nia Exp $

Recent GCC does not like returning NULL from a function that
returns int.

--- src/libmpd-playlist.c.orig	2026-03-23 11:37:03.886761212 +0000
+++ src/libmpd-playlist.c
@@ -780,7 +780,7 @@ int mpd_playlist_load(MpdObj *mi, const 
 	if(mpd_lock_conn(mi))
 	{
 		debug_printf(DEBUG_ERROR,"lock failed\n");
-		return NULL;
+		return 0;
 	}
     mpd_sendLoadCommand(mi->connection,path);
 	mpd_finishCommand(mi->connection);
