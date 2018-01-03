$NetBSD: patch-src_fs__sup.erl,v 1.1 2018/01/03 20:46:55 fhajny Exp $

Properly return "unsupported" on SunOS platforms.
Merged upstream via https://github.com/synrc/fs/pull/54

--- src/fs_sup.erl.orig	2016-12-20 00:10:23.000000000 +0000
+++ src/fs_sup.erl
@@ -10,6 +10,7 @@ init([EventHandler, FileHandler, Path])
     Backend = case os:type() of
         {unix, darwin} -> fsevents;
         {unix, linux} -> inotifywait;
+        {unix, sunos} -> undefined;
         {unix, _} -> kqueue;
         {win32, nt} -> inotifywait_win32;
         _ -> undefined end,
