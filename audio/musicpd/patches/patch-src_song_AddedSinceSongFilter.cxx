$NetBSD: patch-src_song_AddedSinceSongFilter.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/song/AddedSinceSongFilter.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/song/AddedSinceSongFilter.cxx
@@ -6,7 +6,7 @@
 #include "time/ISO8601.hxx"
 #include "util/StringBuffer.hxx"
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 using std::string_view_literals::operator""sv;
 
