$NetBSD: patch-player_main.c,v 1.2 2017/03/10 15:55:33 nat Exp $

Avoid to check mismatched built vs running libraries version.
The use in pkgsrc can be considered a legitimate one.

--- player/main.c.orig	2017-02-12 01:31:16.000000000 +0000
+++ player/main.c
@@ -438,18 +438,6 @@ int mp_initialize(struct MPContext *mpct
 
     handle_deprecated_options(mpctx);
 
-    if (!print_libav_versions(mp_null_log, 0)) {
-        // Using mismatched libraries can be legitimate, but even then it's
-        // a bad idea. We don't acknowledge its usefulness and stability.
-        print_libav_versions(mpctx->log, MSGL_FATAL);
-        MP_FATAL(mpctx, "\nmpv was compiled against a different version of "
-                 "FFmpeg/Libav than the shared\nlibrary it is linked against. "
-                 "This is most likely a broken build and could\nresult in "
-                 "misbehavior and crashes.\n\nmpv does not support this "
-                 "configuration and will not run - rebuild mpv instead.\n");
-        return -1;
-    }
-
     if (!mpctx->playlist->first && !opts->player_idle_mode)
         return -3;
 
