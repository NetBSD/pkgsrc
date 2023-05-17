$NetBSD: patch-src_SongPrint.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10.
https://github.com/MusicPlayerDaemon/MPD/commit/181b96dd2d71bc8f2668776719d344466f258b5d

--- src/SongPrint.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/SongPrint.cxx
@@ -24,6 +24,7 @@
 #include "TagPrint.hxx"
 #include "client/Response.hxx"
 #include "fs/Traits.hxx"
+#include "lib/fmt/AudioFormatFormatter.hxx"
 #include "time/ChronoUtil.hxx"
 #include "util/StringBuffer.hxx"
 #include "util/UriUtil.hxx"
@@ -93,7 +94,7 @@ song_print_info(Response &r, const Light
 		time_print(r, "Last-Modified", song.mtime);
 
 	if (song.audio_format.IsDefined())
-		r.Fmt(FMT_STRING("Format: {}\n"), ToString(song.audio_format));
+		r.Fmt(FMT_STRING("Format: {}\n"), song.audio_format);
 
 	tag_print_values(r, song.tag);
 
@@ -116,7 +117,7 @@ song_print_info(Response &r, const Detac
 		time_print(r, "Last-Modified", song.GetLastModified());
 
 	if (const auto &f = song.GetAudioFormat(); f.IsDefined())
-		r.Fmt(FMT_STRING("Format: {}\n"), ToString(f));
+		r.Fmt(FMT_STRING("Format: {}\n"), f);
 
 	tag_print_values(r, song.GetTag());
 
