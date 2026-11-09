$NetBSD: patch-src_System_FSNotify.hs,v 1.1 2026/11/09 15:07:33 pho Exp $

Fix build with GHC 9.10.3.

TODO: Check whether the upstream has fixed this, which is highly
likely. Otherwise send this patch.

--- src/System/FSNotify.hs.orig	2026-11-09 15:03:27.983985817 +0000
+++ src/System/FSNotify.hs
@@ -124,7 +124,7 @@ defaultConfig = WatchConfig {
   }
 
 defaultOnHandlerException :: SomeException -> IO ()
-defaultOnHandlerException e = putStrLn ("fsnotify: handler threw exception: " <> show e)
+defaultOnHandlerException e = putStrLn ("fsnotify: handler threw exception: " <> Prelude.show e)
 
 -- | Perform an IO action with a WatchManager in place.
 -- Tear down the WatchManager after the action is complete.
