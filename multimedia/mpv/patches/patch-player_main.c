$NetBSD: patch-player_main.c,v 1.5 2019/10/25 14:35:56 leot Exp $

Avoid to check mismatched built vs running libraries version.
The use in pkgsrc can be considered a legitimate one.

--- player/main.c.orig	2019-10-25 13:08:15.000000000 +0000
+++ player/main.c
@@ -384,15 +384,6 @@ int mp_initialize(struct MPContext *mpct
     if (handle_help_options(mpctx))
         return 1; // help
 
-    if (!print_libav_versions(mp_null_log, 0)) {
-        print_libav_versions(mpctx->log, MSGL_FATAL);
-        MP_FATAL(mpctx, "\nmpv was compiled against an incompatible version of "
-                 "FFmpeg/Libav than the shared\nlibrary it is linked against. "
-                 "This is most likely a broken build and could\nresult in "
-                 "misbehavior and crashes.\n\nThis is a broken build.\n");
-        return -1;
-    }
-
     if (!mpctx->playlist->first && !opts->player_idle_mode) {
         // nothing to play
         mp_print_version(mpctx->log, true);
