$NetBSD: patch-src_command_PlayerCommands.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10.
https://github.com/MusicPlayerDaemon/MPD/commit/181b96dd2d71bc8f2668776719d344466f258b5d

--- src/command/PlayerCommands.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/command/PlayerCommands.cxx
@@ -28,6 +28,7 @@
 #include "Partition.hxx"
 #include "Instance.hxx"
 #include "IdleFlags.hxx"
+#include "lib/fmt/AudioFormatFormatter.hxx"
 #include "util/StringBuffer.hxx"
 #include "util/ScopeExit.hxx"
 #include "util/Exception.hxx"
@@ -185,7 +186,7 @@ handle_status(Client &client, [[maybe_un
 
 		if (player_status.audio_format.IsDefined())
 			r.Fmt(FMT_STRING(COMMAND_STATUS_AUDIO ": {}\n"),
-			      ToString(player_status.audio_format));
+			      player_status.audio_format);
 	}
 
 #ifdef ENABLE_DATABASE
