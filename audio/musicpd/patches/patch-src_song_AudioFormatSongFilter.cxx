$NetBSD: patch-src_song_AudioFormatSongFilter.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/song/AudioFormatSongFilter.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/song/AudioFormatSongFilter.cxx
@@ -5,7 +5,7 @@
 #include "LightSong.hxx"
 #include "util/StringBuffer.hxx"
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 using std::string_view_literals::operator""sv;
 
