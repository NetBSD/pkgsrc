$NetBSD: patch-player_main.c,v 1.6 2019/12/28 17:20:33 leot Exp $

Avoid to check mismatched built vs running libraries version.
The use in pkgsrc can be considered a legitimate one.

--- player/main.c.orig	2019-12-28 11:07:07.000000000 +0000
+++ player/main.c
@@ -387,18 +387,6 @@ int mp_initialize(struct MPContext *mpct
     if (handle_help_options(mpctx))
         return 1; // help
 
-    if (!print_libav_versions(mp_null_log, 0)) {
-        // This happens only if the runtime FFmpeg version is lower than the
-        // build version, which will not work according to FFmpeg's ABI rules.
-        // This does not happen if runtime FFmpeg is newer, which is compatible.
-        print_libav_versions(mpctx->log, MSGL_FATAL);
-        MP_FATAL(mpctx, "\nmpv was compiled against an incompatible version of "
-                 "FFmpeg/Libav than the shared\nlibrary it is linked against. "
-                 "This is most likely a broken build and could\nresult in "
-                 "misbehavior and crashes.\n\nThis is a broken build.\n");
-        return -1;
-    }
-
 #if HAVE_TESTS
     if (opts->test_mode && opts->test_mode[0])
         return run_tests(mpctx) ? 1 : -1;
